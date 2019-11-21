//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_object.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeObject::HzDataTypeObject(const HzF2dSemanticType semanticType)
    : HzTypeBase(HzF2dDataType::dt_object, semanticType) {}

hzf2d::HzDataTypeObject::HzDataTypeObject(const hzf2d::HzDataTypeObject &other)
    : HzDataTypeObject(other._semanticType) {}

void hzf2d::HzDataTypeObject::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
}
