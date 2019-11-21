//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_arc.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeArc::HzDataTypeArc(double x, double y, double major,
                                    double minor, float rotation, float start,
                                    float end)
    : HzTypeBase(dt_arc, st_arc), _x(x), _y(y), _major(major), _minor(minor),
      _rotation(rotation), _start(start), _end(end) {}

void hzf2d::HzDataTypeArc::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  HzPointsTransformer &pt = HzPointsTransformer::instance();
  long double lastX = pt.getLastX(), lastY = pt.getLastY(), scaleX = pt.getScaleX(),
         scaleY = pt.getScaleY();
//  double offsetX = _x - lastX, offsetY = _y - lastY;
  HzStreamUtils::convPushPoint(output, _x, lastX, scaleX);
  HzStreamUtils::convPushPoint(output, _y, lastY, scaleY);
  pt.updateLastPoint(_x, _y);

  auto major = static_cast<uint64_t>(_major / scaleX);
  HzStreamUtils::convPushVarints(output, major);
  auto minor = static_cast<uint64_t>(_minor / scaleY);
  HzStreamUtils::convPushVarints(output, minor);

  HzStreamUtils::convPushFloat(output, _rotation);
  HzStreamUtils::convPushFloat(output, _start);
  HzStreamUtils::convPushFloat(output, _end);
}

// void hzf2d::HzDataTypeArc::flush(std::ofstream &output) {
//  HzStreamUtils::convPushVarints(output, _dataType);
//  HzStreamUtils::convPushVarints(output, _semanticType);
//
//  HzPointsTransformer &pt = HzPointsTransformer::instance();
//  double scaleX = pt.getScaleX(), scaleY = pt.getScaleY();
//  HzStreamUtils::convPushPoint(output, _x, scaleX);
//  HzStreamUtils::convPushPoint(output, _y, scaleY);
//
//  auto major = static_cast<uint64_t>(_major / scaleX);
//  HzStreamUtils::convPushVarints(output, major);
//  auto minor = static_cast<uint64_t>(_minor / scaleY);
//  HzStreamUtils::convPushVarints(output, minor);
//
//  HzStreamUtils::convPushFloat(output, _rotation);
//  HzStreamUtils::convPushFloat(output, _start);
//  HzStreamUtils::convPushFloat(output, _end);
//}
