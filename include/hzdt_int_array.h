//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_INT_ARRAY_H
#define F2DUTILIES_HZDT_INT_ARRAY_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeIntArray : public HzTypeBase {
private:
  std::vector<uint32_t> _values;

public:
  HzDataTypeIntArray();

  HzDataTypeIntArray(const HzDataTypeIntArray &other);

  ~HzDataTypeIntArray() override;

  void flush(std::ofstream &output) override;

  void pushValue(uint32_t value);

  bool empty();

private:
  void copy(const HzDataTypeIntArray &other);
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_INT_ARRAY_H
