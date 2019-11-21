//
// Created by rasefon on 2019/1/22.
//

#include "../include/hz_points_transformer.h"

void hzf2d::HzPointsTransformer::setScale(long double scaleX,
                                          long double scaleY) {
  _scaleX = scaleX;
  _scaleY = scaleY;
}

void hzf2d::HzPointsTransformer::updateLastPoint(long double pointX,
                                                 long double pointY) {
  _lastX = pointX;
  _lastY = pointY;
}

long double hzf2d::HzPointsTransformer::getLastX() const { return _lastX; }

long double hzf2d::HzPointsTransformer::getLastY() const { return _lastY; }

long double hzf2d::HzPointsTransformer::getScaleX() const { return _scaleX; }

long double hzf2d::HzPointsTransformer::getScaleY() const { return _scaleY; }
