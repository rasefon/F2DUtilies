//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_layer.h"

hzf2d::HzSemanticTypeLayer::HzSemanticTypeLayer(uint64_t layer)
    : _layer(st_layer, layer) {}

void hzf2d::HzSemanticTypeLayer::flush(std::ofstream &output) {
  _layer.flush(output);
}
