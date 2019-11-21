//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_string.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeString::HzDataTypeString(const std::string &_value)
    : HzTypeBase(dt_string, st_object_member), _value(_value) {}

void hzf2d::HzDataTypeString::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
  HzStreamUtils::convPushVarints(output, _value.length());
  HzStreamUtils::convPushString(output, _value);
}
