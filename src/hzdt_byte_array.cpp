//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_byte_array.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"
#include <algorithm>
#include <iterator>

hzf2d::HzDataTypeByteArray::HzDataTypeByteArray()
    : HzTypeBase(dt_byte_array, st_object_member) {}

hzf2d::HzDataTypeByteArray::~HzDataTypeByteArray() {
  _values.clear();
  _values.shrink_to_fit();
}

void hzf2d::HzDataTypeByteArray::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  SOFT_ASSERT(!_values.empty());
  HzStreamUtils::convPushVarints(output, _values.size());
  for (uint8_t value : _values) {
    HzStreamUtils::convPushUint8(output, value);
  }
}

void hzf2d::HzDataTypeByteArray::pushValue(uint8_t value) {
  _values.emplace_back(value);
}

void hzf2d::HzDataTypeByteArray::copy(const std::vector<uint8_t> &values) {
  std::copy(values.begin(), values.end(), std::back_inserter(_values));
}
