//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_color.h"

hzf2d::HzSemanticTypeColor::HzSemanticTypeColor(uint32_t value)
    : _color(HzF2dSemanticType::st_color, value) {}

void hzf2d::HzSemanticTypeColor::flush(std::ofstream &output) {
  _color.flush(output);
}
