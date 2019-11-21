//
// Created by rasefon on 2019/1/23.
//

#ifndef F2DUTILIES_HZST_END_SHEET_H
#define F2DUTILIES_HZST_END_SHEET_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_object.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeEndSheet : public HzSemanticTypeBase {
private:
  HzDataTypeObject _endObject;
public:
  HzSemanticTypeEndSheet();

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_END_SHEET_H
