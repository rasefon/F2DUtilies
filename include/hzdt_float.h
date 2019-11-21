//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_FLOAT_H
#define F2DUTILIES_HZDT_FLOAT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeFloat : public HzTypeBase {
private:
  float _value;
public:
  HzDataTypeFloat(HzF2dSemanticType semanticType, float value);

  ~HzDataTypeFloat() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_FLOAT_H
