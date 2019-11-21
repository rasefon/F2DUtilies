//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_miter_length.h"

hzf2d::HzSemanticTypeMiterLength::HzSemanticTypeMiterLength(float miterLength)
    : _miterLength(st_miter_length, miterLength) {}

void hzf2d::HzSemanticTypeMiterLength::flush(std::ofstream &output) {
  _miterLength.flush(output);
}
