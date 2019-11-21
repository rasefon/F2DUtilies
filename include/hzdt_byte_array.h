//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_BYTE_ARRAY_H
#define F2DUTILIES_HZDT_BYTE_ARRAY_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeByteArray : public HzTypeBase {
private:
  std::vector<uint8_t> _values;

public:
  HzDataTypeByteArray();

  ~HzDataTypeByteArray() override;

  void copy(const std::vector<uint8_t> &values);

  void flush(std::ofstream &output) override;

  void pushValue(uint8_t value);
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_BYTE_ARRAY_H
