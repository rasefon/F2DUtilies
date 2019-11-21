//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_DOT_H
#define F2DUTILIES_HZST_DOT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"
#include "hzdt_points_array.h"

#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeDot : public HzSemanticTypeBase {
private:
  HzDataTypePointsArray _points;

public:
  HzSemanticTypeDot();

  ~HzSemanticTypeDot() override = default;

  void pushPoints(double x, double y);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_DOT_H
