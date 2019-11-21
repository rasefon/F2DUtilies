//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_int.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeInt::HzDataTypeInt(hzf2d::HzF2dSemanticType semanticType,
                                    uint32_t value)
    : HzTypeBase(HzF2dDataType::dt_int, semanticType), _value(value) {}

void hzf2d::HzDataTypeInt::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
  HzStreamUtils::convPushUint32(output, _value);
}
