//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_fill_off.h"

hzf2d::HzSemanticTypeFillOff::HzSemanticTypeFillOff() : _value(st_fill_off) {}

void hzf2d::HzSemanticTypeFillOff::flush(std::ofstream &output) {
  _value.flush(output);
}
