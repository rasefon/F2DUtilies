//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_begin_sheet.h"

hzf2d::HzSemanticTypeBeginSheet::HzSemanticTypeBeginSheet(uint32_t paperColor)
    : _beginObject(st_sheet), _paperColor(st_object_member, paperColor) {}

void hzf2d::HzSemanticTypeBeginSheet::flush(std::ofstream &output) {
  _beginObject.flush(output);
  _paperColor.flush(output);
}
