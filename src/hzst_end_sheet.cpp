//
// Created by rasefon on 2019/1/23.
//

#include "../include/hzst_end_sheet.h"

hzf2d::HzSemanticTypeEndSheet::HzSemanticTypeEndSheet()
    : _endObject(st_end_object) {}

void hzf2d::HzSemanticTypeEndSheet::flush(std::ofstream &output) {
  _endObject.flush(output);
}
