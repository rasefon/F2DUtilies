//
// Created by rasefon on 2019-07-26.
//

#include "../include/hzst_fill.h"

hzf2d::HzSemanticTypeFill::HzSemanticTypeFill() : _value(st_fill) {

}

void hzf2d::HzSemanticTypeFill::flush(std::ofstream &output) {
  //HzSemanticTypeBase::flush(output);
  _value.flush(output);
}

