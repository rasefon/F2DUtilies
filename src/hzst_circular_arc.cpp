//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_circular_arc.h"

hzf2d::HzSemanticTypeCircularArc::HzSemanticTypeCircularArc(double x, double y,
                                                            double major,
                                                            float start,
                                                            float end)
    : _dtCircularArc(x, y, major, start, end) {}

void hzf2d::HzSemanticTypeCircularArc::flush(std::ofstream &output) {
  _dtCircularArc.flush(output);
}
