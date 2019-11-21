//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_POINTS_TRANSFORMER_H
#define F2DUTILIES_POINTS_TRANSFORMER_H

#include "../public/include/hz_f2d_macros.h"

BEGIN_HZ_F2D_NAMESPACE

class HzPointsTransformer {
private:
  long double _lastX;
  long double _lastY;
  long double _scaleX;
  long double _scaleY;

public:
  static HzPointsTransformer &instance() {
    static HzPointsTransformer _instance;
    return _instance;
  }

  void setScale(long double scaleX, long double scaleY);

  void updateLastPoint(long double pointX, long double pointY);

  long double getLastX() const;

  long double getLastY() const;

  long double getScaleX() const;

  long double getScaleY() const;

private:
  HzPointsTransformer() : _lastX(0), _lastY(0), _scaleX(0), _scaleY(0) {}
  //  HzPointsTransformer() : _scaleX(0), _scaleY(0) {}
};

END_NAMESPACE

#endif // F2DUTILIES_POINTS_TRANSFORMER_H
