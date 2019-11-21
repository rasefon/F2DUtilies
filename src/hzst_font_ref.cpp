//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_font_ref.h"

hzf2d::HzSemanticTypeFontRef::HzSemanticTypeFontRef(uint64_t fontId)
    : _fontId(st_font_ref, fontId) {}

void hzf2d::HzSemanticTypeFontRef::flush(std::ofstream &output) {
  _fontId.flush(output);
}
