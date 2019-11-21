//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_font_def.h"

hzf2d::HzSemanticTypeFontDef::HzSemanticTypeFontDef(
    const std::string &name, const std::string &fullName, uint64_t flags,
    float spacing, const std::vector<uint8_t> &panose)
    : _beginObject(st_font_def), _name(name), _fullName(fullName),
      _flags(st_object_member, flags), _spacing(st_object_member, spacing),
      _endObject(st_end_object) {
  _panose.copy(panose);
}

void hzf2d::HzSemanticTypeFontDef::flush(std::ofstream &output) {
  _beginObject.flush(output);
  _name.flush(output);
  _fullName.flush(output);
  _flags.flush(output);
  _spacing.flush(output);
  _panose.flush(output);
  _endObject.flush(output);
}