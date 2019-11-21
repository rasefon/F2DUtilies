//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_arc.h"

hzf2d::HzSemanticTypeArc::HzSemanticTypeArc(float x, float y, float major,
                                            float minor, float rotation,
                                            float start, float end)
    : _dtArc(x, y, major, minor, rotation, start, end) {}

void hzf2d::HzSemanticTypeArc::flush(std::ofstream &output) {
  _dtArc.flush(output);
}
