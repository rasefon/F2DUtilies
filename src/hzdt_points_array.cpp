//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_points_array.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"
#include <algorithm>
#include <iterator>

hzf2d::HzDataTypePointsArray::HzDataTypePointsArray(
    hzf2d::HzF2dSemanticType semanticType)
    : HzTypeBase(dt_point_varint_array, semanticType) {}

hzf2d::HzDataTypePointsArray::HzDataTypePointsArray(
    const hzf2d::HzDataTypePointsArray &other)
    : HzDataTypePointsArray(other._semanticType) {
  copy(other);
}

hzf2d::HzDataTypePointsArray::~HzDataTypePointsArray() {
  _points.clear();
  _points.shrink_to_fit();
}

void hzf2d::HzDataTypePointsArray::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  SOFT_ASSERT(!_points.empty() && (_points.size() % 2) == 0);
  HzStreamUtils::convPushVarints(output, _points.size());

  HzPointsTransformer &pt = HzPointsTransformer::instance();
  long double scaleX = pt.getScaleX(), scaleY = pt.getScaleY();
  long double lastX = pt.getLastX(), lastY = pt.getLastY();
//  long double offsetX = 0, offsetY = 0;
  for (size_t i = 0; i < _points.size(); i += 2) {
    double x = _points[i], y = _points[i + 1];
//    offsetX = x - lastX;
//    offsetY = y - lastY;
    HzStreamUtils::convPushPoint(output, x, lastX, scaleX);
    HzStreamUtils::convPushPoint(output, y, lastY, scaleY);
    lastX = x;
    lastY = y;
    pt.updateLastPoint(lastX, lastY);
  }
}

// void hzf2d::HzDataTypePointsArray::flush(std::ofstream &output) {
//  HzStreamUtils::convPushVarints(output, _dataType);
//  HzStreamUtils::convPushVarints(output, _semanticType);
//
//  SOFT_ASSERT(!_points.empty() && (_points.size() % 2) == 0);
//  HzStreamUtils::convPushVarints(output, _points.size());
//
//  HzPointsTransformer &pt = HzPointsTransformer::instance();
//  double scaleX = pt.getScaleX(), scaleY = pt.getScaleY();
//  for (size_t i = 0; i < _points.size(); i += 2) {
//    double x = _points[i], y = _points[i + 1];
//    HzStreamUtils::convPushPoint(output, x, scaleX);
//    HzStreamUtils::convPushPoint(output, y, scaleY);
//  }
//}

void hzf2d::HzDataTypePointsArray::pushPoints(double x, double y) {
  _points.emplace_back(x);
  _points.emplace_back(y);
}

void hzf2d::HzDataTypePointsArray::copy(
    const hzf2d::HzDataTypePointsArray &other) {
  std::copy(other._points.begin(), other._points.end(),
            std::back_inserter(_points));
}

bool hzf2d::HzDataTypePointsArray::empty() { return _points.empty(); }
