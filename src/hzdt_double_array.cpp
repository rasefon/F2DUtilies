//
// Created by rasefon on 2019/1/22.
//

#include "../include/hzdt_double_array.h"
#include "../include/hz_points_transformer.h"
#include "../include/hz_stream_utils.h"
#include <algorithm>
#include <iterator>

hzf2d::HzDataTypeDoubleArray::HzDataTypeDoubleArray()
    : HzTypeBase(dt_double_array, st_object_member) {}

hzf2d::HzDataTypeDoubleArray::HzDataTypeDoubleArray(
    const std::vector<double> values)
    : HzTypeBase(dt_double_array, st_object_member) {
  std::copy(values.begin(), values.end(), std::back_inserter(_values));
}

hzf2d::HzDataTypeDoubleArray::~HzDataTypeDoubleArray() {
  _values.clear();
  _values.shrink_to_fit();
}

void hzf2d::HzDataTypeDoubleArray::flush(std::ofstream &output) {
  HzStreamUtils::convPushVarints(output, _dataType);
  HzStreamUtils::convPushVarints(output, _semanticType);

  SOFT_ASSERT(!_values.empty());
  HzStreamUtils::convPushVarints(output, _values.size());
  for (double value : _values) {
    HzStreamUtils::convPushDouble(output, value);
  }
}

void hzf2d::HzDataTypeDoubleArray::pushValue(double value) {
  _values.emplace_back(value);
}
