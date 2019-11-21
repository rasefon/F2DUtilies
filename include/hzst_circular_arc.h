//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_CIRCULAR_ARC_H
#define F2DUTILIES_HZST_CIRCULAR_ARC_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_circular_arc.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeCircularArc : public HzSemanticTypeBase {
private:
  HzDataTypeCircularArc _dtCircularArc;

public:
  HzSemanticTypeCircularArc(double x, double y, double major, float start,
                            float end);

  ~HzSemanticTypeCircularArc() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_CIRCULAR_ARC_H
