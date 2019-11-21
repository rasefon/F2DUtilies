//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_CIRCLE_H
#define F2DUTILIES_HZDT_CIRCLE_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeCircle: public HzTypeBase {
private:
  double _x;
  double _y;
  double _radius;

public:
  HzDataTypeCircle(double x, double y, double radius);

  ~HzDataTypeCircle() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_CIRCLE_H
