//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_void.h"
#include "../include/hz_stream_utils.h"

hzf2d::HzDataTypeVoid::HzDataTypeVoid(HzF2dSemanticType semanticType)
    : HzTypeBase(dt_void, semanticType) {}

void hzf2d::HzDataTypeVoid::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);
}
