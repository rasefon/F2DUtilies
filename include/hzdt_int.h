//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_INT_H
#define F2DUTILIES_HZDT_INT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeInt : public HzTypeBase {
private:
  uint32_t _value;

public:
  HzDataTypeInt(HzF2dSemanticType semanticType, uint32_t value);

  ~HzDataTypeInt() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_INT_H
