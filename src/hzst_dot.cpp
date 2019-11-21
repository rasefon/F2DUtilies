//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_dot.h"

hzf2d::HzSemanticTypeDot::HzSemanticTypeDot() : _points(st_dot) {}

void hzf2d::HzSemanticTypeDot::pushPoints(const double x, const double y) {
  _points.pushPoints(x, y);
}

void hzf2d::HzSemanticTypeDot::flush(std::ofstream &output) {
  _points.flush(output);
}
