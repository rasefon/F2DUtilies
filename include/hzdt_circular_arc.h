//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_CIRCULAR_ARC_H
#define F2DUTILIES_HZDT_CIRCULAR_ARC_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypeCircularArc : public HzTypeBase {
private:
  double _x;
  double _y;
  double _major;
  float _start;
  float _end;

public:
  HzDataTypeCircularArc(double x, double y, double major, float start,
                        float end);

  ~HzDataTypeCircularArc() override = default;

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_CIRCULAR_ARC_H
