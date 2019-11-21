//
// Created by rasefon on 2019/1/23.
//

#include "../public/include/hz_f2d_exporter.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"
#include "../include/hzst_arc.h"
#include "../include/hzst_begin_sheet.h"
#include "../include/hzst_circle.h"
#include "../include/hzst_circular_arc.h"
#include "../include/hzst_clip.h"
#include "../include/hzst_color.h"
#include "../include/hzst_color_fill.h"
#include "../include/hzst_dot.h"
#include "../include/hzst_end_sheet.h"
#include "../include/hzst_fill_off.h"
#include "../include/hzst_font_def.h"
#include "../include/hzst_font_ref.h"
#include "../include/hzst_layer.h"
#include "../include/hzst_line_weight.h"
#include "../include/hzst_miter_angle.h"
#include "../include/hzst_miter_length.h"
#include "../include/hzst_object_id.h"
#include "../include/hzst_polyline.h"
#include "../include/hzst_polytriangle.h"
#include "../include/hzst_text.h"
#include "../include/hzst_viewport.h"
#include "../include/hzst_fill.h"
#include <fstream>

hzf2d::HzF2dExporter::HzF2dExporter(const std::string &outputFilePath,
                                    long double scaleX, long double scaleY)
    : _outputFn(outputFilePath) {
  HzPointsTransformer &pt = HzPointsTransformer::instance();
  pt.setScale(scaleX, scaleY);
}

hzf2d::HzF2dExporter::~HzF2dExporter() {
  for (size_t i = 0; i < _objects.size(); ++i) {
    delete _objects[i];
    _objects[i] = nullptr;
  }
  _objects.clear();
  _objects.shrink_to_fit();
}

void hzf2d::HzF2dExporter::beginSheet(uint32_t paperColor) {
  auto *pObject = new HzSemanticTypeBeginSheet(paperColor);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::endSheet() {
  auto *pObject = new HzSemanticTypeEndSheet();
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::beginObject(uint32_t objectId) {
  auto *pObject = new HzSemanticTypeObjectId(objectId);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setColor(uint32_t color) {
  auto *pObject = new HzSemanticTypeColor(color);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setLineWeight(uint64_t lineWeight) {
  auto *pObject = new HzSemanticTypeLineWeight(lineWeight);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setMiterAngle(float miterAngle) {
  auto *pObject = new HzSemanticTypeMiterAngle(miterAngle);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setMiterLength(float miterLength) {
  auto *pObject = new HzSemanticTypeMiterLength(miterLength);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setViewPort(const std::string &units,
                                       const std::vector<double> &transform) {
  auto *pObject = new HzSemanticTypeViewPort(units, transform);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setLayer(uint64_t layerId) {
  auto *pObject = new HzSemanticTypeLayer(layerId);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setColorFill(uint32_t color) {
  auto *pObject = new HzSemanticTypeColorFill(color);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setFillOff() {
  auto *pObject = new HzSemanticTypeFillOff();
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::setFill() {
  auto *pObject = new HzSemanticTypeFill();
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushArc(float x, float y, float major, float minor,
                                   float rotation, float start, float end) {
  auto *pObject =
      new HzSemanticTypeArc(x, y, major, minor, rotation, start, end);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushCircle(double x, double y, double radius) {
  auto *pObject = new HzSemanticTypeCircle(x, y, radius);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushCirclarArc(double x, double y, double major,
                                          float start, float end) {
  auto *pObject = new HzSemanticTypeCircularArc(x, y, major, start, end);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushClip(uint64_t counts,
                                    const std::vector<double> &points,
                                    const std::vector<uint64_t> &indices) {
  size_t pointCount = points.size();
  SOFT_ASSERT((pointCount % 2) == 0);
  pointCount /= 2;

  auto *pObject = new HzSemanticTypeClip();
  pObject->pushContourCounts(counts);

  for (size_t i = 0; i < points.size(); i += 2) {
    pObject->pushPoints(points[i], points[i + 1]);
  }

  for (size_t i = 0; i < indices.size(); ++i) {
    uint64_t index = indices[i];
    SOFT_ASSERT(index < pointCount);
    pObject->pushIndex(index);
  }

  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushDot(const std::vector<double> &points) {
  SOFT_ASSERT(!points.empty());

  auto *pObject = new HzSemanticTypeDot();
  size_t pointCount = points.size();
  SOFT_ASSERT((pointCount % 2) == 0);

  for (size_t i = 0; i < points.size(); i += 2) {
    pObject->pushPoints(points[i], points[i + 1]);
  }

  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushFontDef(const std::string &name,
                                       const std::string &fullName,
                                       uint64_t flags, float spacing,
                                       const std::vector<uint8_t> &panose) {
  auto *pObject =
      new HzSemanticTypeFontDef(name, fullName, flags, spacing, panose);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushFontRef(uint64_t fontId) {
  auto *pObject = new HzSemanticTypeFontRef(fontId);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushPolylines(const std::vector<double> &points) {
  auto *pObject = new HzSemanticTypePolyline();
  size_t pointCount = points.size();
  SOFT_ASSERT((pointCount % 2) == 0);

  for (size_t i = 0; i < points.size(); i += 2) {
    pObject->pushPoint(points[i], points[i + 1]);
  }

  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushPolytriangles(
    const std::vector<double> &points, const std::vector<uint64_t> &indices,
    const std::vector<uint32_t> &colors) {
  auto *pObject = new HzSemanticTypePolytriangle();

  size_t pointCount = points.size();
  SOFT_ASSERT((pointCount % 2) == 0);
  pointCount /= 2;
  SOFT_ASSERT(colors.size() == pointCount);

  for (size_t i = 0; i < points.size(); i += 2) {
    pObject->pushPoints(points[i], points[i + 1]);
  }

  for (size_t i = 0; i < indices.size(); ++i) {
    SOFT_ASSERT(indices[i] < pointCount);
    pObject->pushIndices(indices[i]);
  }

  for (size_t i = 0; i < colors.size(); ++i) {
    pObject->pushColors(colors[i]);
  }

  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::pushText(const std::string &str, double x, double y,
                                    uint64_t height, float widthScale,
                                    float rotation, float oblique,
                                    const std::vector<double> &points,
                                    const std::vector<uint64_t> &indices,
                                    const std::vector<uint32_t> &colors) {
  auto *pPolyTriangles = new HzSemanticTypePolytriangle();

  size_t pointCount = points.size();
  SOFT_ASSERT((pointCount % 2) == 0);
  pointCount /= 2;
  SOFT_ASSERT(colors.size() == pointCount);

  for (size_t i = 0; i < points.size(); i += 2) {
    pPolyTriangles->pushPoints(points[i], points[i + 1]);
  }

  for (size_t i = 0; i < indices.size(); ++i) {
    SOFT_ASSERT(indices[i] < pointCount);
    pPolyTriangles->pushIndices(indices[i]);
  }

  for (size_t i = 0; i < colors.size(); ++i) {
    pPolyTriangles->pushColors(colors[i]);
  }

  auto *pObject = new HzSemanticTypeText(str, x, y, height, widthScale,
                                         rotation, oblique, *pPolyTriangles);
  _objects.emplace_back(pObject);
}

void hzf2d::HzF2dExporter::writeToFile() {
  std::ofstream output;
  output.open(_outputFn, std::ios::binary | std::ios::trunc);
  HzStreamUtils::writeHeader(output, "01");
  for (auto &pObject : _objects) {
    pObject->flush(output);
  }
  output.close();
}


