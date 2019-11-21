//
// Created by rasefon on 2019/1/23.
//

#include "../include/hzst_clip.h"

hzf2d::HzSemanticTypeClip::HzSemanticTypeClip()
    : _beginObject(st_clip), _points(st_object_member),
      _endObject(st_end_object) {}

void hzf2d::HzSemanticTypeClip::pushContourCounts(uint64_t counts) {
  _contourCounts.pushValue(counts);
}

void hzf2d::HzSemanticTypeClip::pushPoints(double x, double y) {
  _points.pushPoints(x, y);
}

void hzf2d::HzSemanticTypeClip::pushIndex(uint64_t index) {
  _indices.pushValue(index);
}

void hzf2d::HzSemanticTypeClip::flush(std::ofstream &output) {
  _beginObject.flush(output);
  _contourCounts.flush(output);
  _points.flush(output);
  _indices.flush(output);
  _endObject.flush(output);
}
