//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_varint_array.h"
#include "../include/hz_stream_utils.h"
#include <algorithm>
#include <iterator>

hzf2d::HzDataTypeVarintArray::HzDataTypeVarintArray()
    : HzTypeBase(dt_varint_array, st_object_member) {}

hzf2d::HzDataTypeVarintArray::HzDataTypeVarintArray(
    const hzf2d::HzDataTypeVarintArray &other)
    : HzDataTypeVarintArray() {
  copy(other);
}

hzf2d::HzDataTypeVarintArray::~HzDataTypeVarintArray() {
  _values.clear();
  _values.shrink_to_fit();
}

void hzf2d::HzDataTypeVarintArray::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  SOFT_ASSERT(!_values.empty());
  HzStreamUtils::convPushVarints(output, _values.size());
  for (uint64_t value : _values) {
    HzStreamUtils::convPushVarints(output, value);
  }
}

void hzf2d::HzDataTypeVarintArray::pushValue(uint64_t value) {
  _values.emplace_back(value);
}

void hzf2d::HzDataTypeVarintArray::copy(
    const hzf2d::HzDataTypeVarintArray &other) {
  std::copy(other._values.begin(), other._values.end(),
            std::back_inserter(_values));
}

bool hzf2d::HzDataTypeVarintArray::empty() {
  return _values.empty();
}
