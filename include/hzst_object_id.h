//
// Created by rasefon on 2019/1/23.
//

#ifndef F2DUTILIES_HZST_COMPOSED_OBJECT_H
#define F2DUTILIES_HZST_COMPOSED_OBJECT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_varint.h"
#include "../public/include/hzst_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeObjectId : public HzSemanticTypeBase {
private:
  HzDataTypeVarint _objectId;

public:
  HzSemanticTypeObjectId(uint64_t objectId);

  ~HzSemanticTypeObjectId() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_COMPOSED_OBJECT_H
