//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_VARINT_H
#define F2DUTILIES_HZDT_VARINT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeVarint : public HzTypeBase {
private:
  uint64_t _value;

public:
  HzDataTypeVarint(HzF2dSemanticType semanticType, uint64_t value);

  void setValue(uint64_t value);

  ~HzDataTypeVarint() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_VARINT_H
