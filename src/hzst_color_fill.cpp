//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_color_fill.h"

hzf2d::HzSemanticTypeColorFill::HzSemanticTypeColorFill(uint32_t value)
    : _value(st_fill, value) {}

void hzf2d::HzSemanticTypeColorFill::flush(std::ofstream &output) {
  _value.flush(output);
}
