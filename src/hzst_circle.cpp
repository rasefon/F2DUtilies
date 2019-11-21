//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_circle.h"

hzf2d::HzSemanticTypeCircle::HzSemanticTypeCircle(double x, double y,
                                                  double radius)
    : _dtCircle(x, y, radius) {}

void hzf2d::HzSemanticTypeCircle::flush(std::ofstream &output) {
  _dtCircle.flush(output);
}
