//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_float.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeFloat::HzDataTypeFloat(hzf2d::HzF2dSemanticType semanticType,
                                        float value)
    : HzTypeBase(dt_float, semanticType), _value(value) {}

void hzf2d::HzDataTypeFloat::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
  HzStreamUtils::convPushFloat(output, _value);
}
