//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_VARINT_ARRAY_H
#define F2DUTILIES_HZDT_VARINT_ARRAY_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeVarintArray : public HzTypeBase {
private:
  std::vector<uint64_t> _values;

public:
  HzDataTypeVarintArray();

  HzDataTypeVarintArray(const HzDataTypeVarintArray &other);

  ~HzDataTypeVarintArray() override;

  void flush(std::ofstream &output) override;

  void pushValue(uint64_t value);

  bool empty();

private:
  void copy(const HzDataTypeVarintArray &other);
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_VARINT_ARRAY_H
