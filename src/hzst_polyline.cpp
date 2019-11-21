//
// Created by rasefon on 2019/1/21.
//

#include "../include/hzst_polyline.h"

hzf2d::HzSemanticTypePolyline::HzSemanticTypePolyline()
    : _polylines(st_polyline) {}


void hzf2d::HzSemanticTypePolyline::flush(std::ofstream &output) {
  _polylines.flush(output);
}

void hzf2d::HzSemanticTypePolyline::pushPoint(double x, double y) {
  _polylines.pushPoints(x, y);
}

