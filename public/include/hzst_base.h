//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZST_BASE_H
#define F2DUTILIES_HZST_BASE_H

#include "hz_f2d_common.h"
#include "hz_f2d_macros.h"

BEGIN_HZ_F2D_NAMESPACE

class HZ_F2D_API HzSemanticTypeBase {
public:
  virtual void flush(std::ofstream &output) {
    SOFT_ASSERT(false);
  }

  virtual ~HzSemanticTypeBase() = default;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_BASE_H
