//
// Created by rasefon on 2019/1/23.
//

#ifndef F2DUTILIES_HZ_F2D_EXPORTER_H
#define F2DUTILIES_HZ_F2D_EXPORTER_H

#include "hz_f2d_common.h"
#include "hzst_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HZ_F2D_API HzF2dExporter {
private:
  std::vector<HzSemanticTypeBase *> _objects;
  std::string _outputFn;

public:
  HzF2dExporter(const std::string &outputFilePath, long double scaleX, long double scaleY);

  ~HzF2dExporter();

  void writeToFile();

  void beginSheet(uint32_t paperColor);

  void endSheet();

  void beginObject(uint32_t objectId);

  void setColor(uint32_t color);

  void setLineWeight(uint64_t lineWeight);

  void setMiterAngle(float miterAngle);

  void setMiterLength(float miterLength);

  void setViewPort(const std::string &units,
                   const std::vector<double> &transform);

  void setLayer(uint64_t layerId);

  void setColorFill(uint32_t color);

  void setFill();

  void setFillOff();

  void pushArc(float x, float y, float major, float minor, float rotation,
               float start, float end);

  void pushCircle(double x, double y, double radius);

  void pushCirclarArc(double x, double y, double major, float start, float end);

  // check if points length % 2 == 0 and if each index is less than length of
  // points.
  void pushClip(uint64_t counts, const std::vector<double> &points,
                const std::vector<uint64_t> &indices);

  // check if points length % 2 == 0.
  void pushDot(const std::vector<double> &points);

  void pushFontDef(const std::string &name, const std::string &fullName,
                   uint64_t flags, float spacing,
                   const std::vector<uint8_t> &panose);

  void pushFontRef(uint64_t fontId);

  // check if points length % 2 == 0.
  void pushPolylines(const std::vector<double> &points);

  // check if points length % 2 == 0, and if each index is less than length of
  // points, and colors length == points length / 2.
  void pushPolytriangles(const std::vector<double> &points,
                         const std::vector<uint64_t> &indices,
                         const std::vector<uint32_t> &colors);

  // check if points length % 2 == 0, and if each index is less than length of
  // points, and colors length == points length / 2.
  void pushText(const std::string &str, double x, double y, uint64_t height,
                float widthScale, float rotation, float oblique,
                const std::vector<double> &points,
                const std::vector<uint64_t> &indices,
                const std::vector<uint32_t> &colors);
};

END_NAMESPACE

#endif // F2DUTILIES_HZ_F2D_EXPORTER_H
