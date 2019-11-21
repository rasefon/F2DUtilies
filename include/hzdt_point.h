//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_POINT_H
#define F2DUTILIES_HZDT_POINT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypePoint : public HzTypeBase {
private:
  double _x, _y;

public:
  HzDataTypePoint(double x, double y);

  ~HzDataTypePoint() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_POINT_H
