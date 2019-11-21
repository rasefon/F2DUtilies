//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_SHEET_H
#define F2DUTILIES_HZST_SHEET_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_int.h"
#include "hzdt_object.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeBeginSheet : public HzSemanticTypeBase {
private:
  HzDataTypeObject _beginObject;
  HzDataTypeInt _paperColor;

public:
  explicit HzSemanticTypeBeginSheet(uint32_t paperColor);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_SHEET_H
