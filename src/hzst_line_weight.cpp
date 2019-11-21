//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_line_weight.h"
#include "../include/hz_points_transformer.h"

hzf2d::HzSemanticTypeLineWeight::HzSemanticTypeLineWeight(uint64_t lineWeight)
    : _lineWeight(st_line_weight, lineWeight) {}

void hzf2d::HzSemanticTypeLineWeight::flush(std::ofstream &output) {
  _lineWeight.flush(output);
}
