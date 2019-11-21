//
// Created by rasefon on 2019/1/20.
//

#ifndef F2DUTILIES_HZST_MITER_LENGTH_H
#define F2DUTILIES_HZST_MITER_LENGTH_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_float.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeMiterLength : public HzSemanticTypeBase {
private:
  HzDataTypeFloat _miterLength;
public:
  HzSemanticTypeMiterLength(float miterLength);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_MITER_LENGTH_H
