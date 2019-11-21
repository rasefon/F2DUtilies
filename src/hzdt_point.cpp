//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_point.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypePoint::HzDataTypePoint(double x, double y)
    : HzTypeBase(HzF2dDataType::dt_point_varint,
                 HzF2dSemanticType::st_object_member),
      _x(x), _y(y) {}

void hzf2d::HzDataTypePoint::flush(std::ofstream &output) {
  HzPointsTransformer &pt = HzPointsTransformer::instance();
  long double lastX = pt.getLastX(), lastY = pt.getLastY(), scaleX = pt.getScaleX(),
         scaleY = pt.getScaleY();
//  double offsetX = _x - lastX, offsetY = _y - lastY;
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
  HzStreamUtils::convPushPoint(output, _x, lastX, scaleX);
  HzStreamUtils::convPushPoint(output, _y, lastY, scaleY);
  pt.updateLastPoint(_x, _y);
}

// void hzf2d::HzDataTypePoint::flush(std::ofstream &output) {
//  HzPointsTransformer &pt = HzPointsTransformer::instance();
//  double scaleX = pt.getScaleX(), scaleY = pt.getScaleY();
//  HzStreamUtils::convPushVarints(output, _dataType);
//  HzStreamUtils::convPushVarints(output, _semanticType);
//  HzStreamUtils::convPushPoint(output, _x, scaleX);
//  HzStreamUtils::convPushPoint(output, _y, scaleY);
//}