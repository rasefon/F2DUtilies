//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_polytriangle.h"

hzf2d::HzSemanticTypePolytriangle::HzSemanticTypePolytriangle()
    : _beginObject(st_polytriangle), _points(st_object_member),
      _endObject(st_end_object) {}

void hzf2d::HzSemanticTypePolytriangle::pushPoints(double x, double y) {
  _points.pushPoints(x, y);
}

void hzf2d::HzSemanticTypePolytriangle::pushIndices(uint64_t index) {
  _indices.pushValue(index);
}

void hzf2d::HzSemanticTypePolytriangle::pushColors(uint32_t color) {
  _colors.pushValue(color);
}

void hzf2d::HzSemanticTypePolytriangle::flush(std::ofstream &output) {
  _beginObject.flush(output);

  if (_points.empty()) {
    SOFT_ASSERT(_points.empty() && _indices.empty() && _colors.empty());
  } else {
    _points.flush(output);
    _indices.flush(output);
    _colors.flush(output);
    _endObject.flush(output);
  }
}

hzf2d::HzSemanticTypePolytriangle::HzSemanticTypePolytriangle(
    const hzf2d::HzSemanticTypePolytriangle &other)
    : _beginObject(other._beginObject), _points(other._points),
      _indices(other._indices), _colors(other._colors),
      _endObject(other._endObject) {}
