//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_POLYLINE_H
#define F2DUTILIES_HZST_POLYLINE_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_points_array.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypePolyline : public HzSemanticTypeBase {
private:
  HzDataTypePointsArray _polylines;
public:
  HzSemanticTypePolyline();

  ~HzSemanticTypePolyline() override = default;

  void flush(std::ofstream &output) override;

  void pushPoint(double x, double y);
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_POLYLINE_H
