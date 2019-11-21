//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_miter_angle.h"

hzf2d::HzSemanticTypeMiterAngle::HzSemanticTypeMiterAngle(float miterAngle)
    : _miterAngle(st_miter_angle, miterAngle) {}

void hzf2d::HzSemanticTypeMiterAngle::flush(std::ofstream &output) {
  _miterAngle.flush(output);
}
