//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_viewport.h"

hzf2d::HzSemanticTypeViewPort::HzSemanticTypeViewPort(
    const std::string &units, const std::vector<double> &transform)
    : _beginObject(st_viewport), _units(units), _transform(transform),
      _endObject(st_end_object) {}

void hzf2d::HzSemanticTypeViewPort::flush(std::ofstream &output) {
  _beginObject.flush(output);
  _units.flush(output);
  _transform.flush(output);
  _endObject.flush(output);
}
