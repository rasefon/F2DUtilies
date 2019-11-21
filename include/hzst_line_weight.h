//
// Created by rasefon on 2019/1/20.
//

#ifndef F2DUTILIES_HZST_LINE_WEIGHT_H
#define F2DUTILIES_HZST_LINE_WEIGHT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"
#include "hzdt_varint.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeLineWeight : public HzSemanticTypeBase {
private:
  HzDataTypeVarint _lineWeight; // be care to scaleX before output!
public:
  explicit HzSemanticTypeLineWeight(uint64_t lineWeight);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_LINE_WEIGHT_H
