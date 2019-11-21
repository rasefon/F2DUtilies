//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_varint.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeVarint::HzDataTypeVarint(const HzF2dSemanticType semanticType,
                                          const uint64_t value)
    : HzTypeBase(HzF2dDataType::dt_varint, semanticType), _value(value) {}

void hzf2d::HzDataTypeVarint::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
  HzStreamUtils::convPushVarints(output, _value);
}

void hzf2d::HzDataTypeVarint::setValue(uint64_t value) {
  _value = value;
}
