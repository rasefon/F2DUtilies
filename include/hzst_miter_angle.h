//
// Created by rasefon on 2019/1/20.
//

#ifndef F2DUTILIES_HZST_MITER_ANGLE_H
#define F2DUTILIES_HZST_MITER_ANGLE_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_float.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeMiterAngle : public HzSemanticTypeBase {
private:
  HzDataTypeFloat _miterAngle;
public:
  HzSemanticTypeMiterAngle(float miterAngle);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_MITER_ANGLE_H
