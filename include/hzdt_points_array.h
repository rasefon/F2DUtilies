//
// Created by rasefon on 2019/1/22.
//

#ifndef F2DUTILIES_HZDT_POINTS_ARRAY_H
#define F2DUTILIES_HZDT_POINTS_ARRAY_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include <vector>

BEGIN_HZ_F2D_NAMESPACE

class HzDataTypePointsArray : public HzTypeBase {
private:
  std::vector<double> _points;

public:
  explicit HzDataTypePointsArray(HzF2dSemanticType semanticType);

  HzDataTypePointsArray(const HzDataTypePointsArray &other);

  ~HzDataTypePointsArray() override;

  void flush(std::ofstream &output) override;

  void pushPoints(double x, double y);

  bool empty();

private:
  void copy(const HzDataTypePointsArray &other);
};

END_NAMESPACE

#endif // F2DUTILIES_HZDT_POINTS_ARRAY_H
