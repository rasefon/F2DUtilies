//
// Created by rasefon on 2019/1/20.
//

#ifndef F2DUTILIES_HZST_FILL_OFF_H
#define F2DUTILIES_HZST_FILL_OFF_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"
#include "hzdt_void.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeFillOff : public HzSemanticTypeBase {
private:
  HzDataTypeVoid _value;
public:
  HzSemanticTypeFillOff();

  ~HzSemanticTypeFillOff() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_FILL_OFF_H
