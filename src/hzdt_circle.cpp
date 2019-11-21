//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_circle.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeCircle::HzDataTypeCircle(double x, double y, double radius)
    : HzTypeBase(dt_circle, st_arc), _x(x), _y(y), _radius(radius) {}

void hzf2d::HzDataTypeCircle::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  HzPointsTransformer &pt = HzPointsTransformer::instance();
  long double lastX = pt.getLastX(), lastY = pt.getLastY(), scaleX = pt.getScaleX(),
         scaleY = pt.getScaleY();
//  double offsetX = _x - lastX, offsetY = _y - lastY;
  HzStreamUtils::convPushPoint(output, _x, lastX, scaleX);
  HzStreamUtils::convPushPoint(output, _y, lastY, scaleY);
  pt.updateLastPoint(_x, _y);

  auto radius = static_cast<uint64_t>(_radius / scaleX);
  HzStreamUtils::convPushVarints(output, radius);
}

// void hzf2d::HzDataTypeCircle::flush(std::ofstream &output) {
//  HzStreamUtils::convPushVarints(output, _dataType);
//  HzStreamUtils::convPushVarints(output, _semanticType);
//
//  HzPointsTransformer &pt = HzPointsTransformer::instance();
//  double scaleX = pt.getScaleX(), scaleY = pt.getScaleY();
//  HzStreamUtils::convPushPoint(output, _x, scaleX);
//  HzStreamUtils::convPushPoint(output, _y, scaleY);
//  auto radius = static_cast<uint64_t>(_radius / scaleX);
//  HzStreamUtils::convPushVarints(output, radius);
//}
