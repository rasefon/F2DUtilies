//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_text.h"

hzf2d::HzSemanticTypeText::HzSemanticTypeText(
    const std::string &str, const double x, const double y, uint64_t height,
    float widthScale, float rotation, float oblique,
    const hzf2d::HzSemanticTypePolytriangle &polytriangle)
    : _beginObject(st_text), _str(str), _position(x, y),
      _height(st_object_member, height),
      _widthScale(st_object_member, widthScale),
      _rotation(st_object_member, rotation),
      _oblique(st_object_member, oblique), _polytriangle(polytriangle),
      _endObject(st_end_object) {}

void hzf2d::HzSemanticTypeText::pushCharWidth(uint64_t value) {
  _charWidths.pushValue(value);
}

void hzf2d::HzSemanticTypeText::flush(std::ofstream &output) {
  _beginObject.flush(output);
  _str.flush(output);
  _position.flush(output);
  _height.flush(output);
  _widthScale.flush(output);
  _rotation.flush(output);
  _oblique.flush(output);
  _charWidths.flush(output);
  _polytriangle.flush(output);
  _endObject.flush(output);
}
