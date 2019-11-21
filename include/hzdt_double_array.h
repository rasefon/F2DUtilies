//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_DOUBLE_ARRAY_H
#define F2DUTILIES_HZDT_DOUBLE_ARRAY_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeDoubleArray : public HzTypeBase {
private:
  std::vector<double> _values;

public:
  HzDataTypeDoubleArray();

  explicit HzDataTypeDoubleArray(std::vector<double> values);

  ~HzDataTypeDoubleArray() override;

  void flush(std::ofstream &output) override;

  void pushValue(double value);
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_DOUBLE_ARRAY_H
