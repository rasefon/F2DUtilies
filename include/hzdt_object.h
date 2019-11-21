//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZST_OBJECT_H
#define F2DUTILIES_HZST_OBJECT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeObject : public HzTypeBase {
public:
  explicit HzDataTypeObject(HzF2dSemanticType semanticType);

  HzDataTypeObject(const HzDataTypeObject& other);

  ~HzDataTypeObject() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_OBJECT_H
