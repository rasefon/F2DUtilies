//
// Created by rasefon on 2019-07-26.
//

#ifndef HZF2DUTILIES_HZST_FILL_H
#define HZF2DUTILIES_HZST_FILL_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"
#include "hzdt_void.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeFill : public HzSemanticTypeBase {
private:
  HzDataTypeVoid _value;
public:
  HzSemanticTypeFill();

  ~HzSemanticTypeFill() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif //HZF2DUTILIES_HZST_FILL_H
