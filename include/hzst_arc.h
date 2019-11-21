//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_ARC_H
#define F2DUTILIES_HZST_ARC_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_arc.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeArc : public HzSemanticTypeBase {
private:
  HzDataTypeArc _dtArc;

public:
  HzSemanticTypeArc(float x, float y, float major, float minor, float rotation,
                    float start, float end);

  ~HzSemanticTypeArc() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_ARC_H
