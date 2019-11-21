//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_COLOR_H
#define F2DUTILIES_HZST_COLOR_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_int.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeColor : public HzSemanticTypeBase {
private:
  HzDataTypeInt _color;

public:
  HzSemanticTypeColor(uint32_t value);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_COLOR_H
