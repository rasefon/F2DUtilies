//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_FONT_REF_H
#define F2DUTILIES_HZST_FONT_REF_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"
#include "hzdt_varint.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeFontRef : public HzSemanticTypeBase {
private:
  HzDataTypeVarint _fontId;
public:
  HzSemanticTypeFontRef(uint64_t fontId);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_FONT_REF_H
