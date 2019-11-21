//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_int_array.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"
#include <algorithm>
#include <iterator>

hzf2d::HzDataTypeIntArray::HzDataTypeIntArray()
    : HzTypeBase(dt_int_array, st_object_member) {}

hzf2d::HzDataTypeIntArray::HzDataTypeIntArray(
    const hzf2d::HzDataTypeIntArray &other)
    : HzDataTypeIntArray() {
  copy(other);
}

hzf2d::HzDataTypeIntArray::~HzDataTypeIntArray() {
  _values.clear();
  _values.shrink_to_fit();
}

void hzf2d::HzDataTypeIntArray::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  SOFT_ASSERT(!_values.empty());
  HzStreamUtils::convPushVarints(output, _values.size());
  for (uint32_t value : _values) {
    HzStreamUtils::convPushUint32(output, value);
  }
}

void hzf2d::HzDataTypeIntArray::pushValue(const uint32_t value) {
  _values.emplace_back(value);
}

void hzf2d::HzDataTypeIntArray::copy(const hzf2d::HzDataTypeIntArray &other) {
  std::copy(other._values.begin(), other._values.end(),
            std::back_inserter(_values));
}

bool hzf2d::HzDataTypeIntArray::empty() {
  return _values.empty();
}
