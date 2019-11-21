//
// Created by rasefon on 2019/1/23.
//

#ifndef F2DUTILIES_HZST_CLIP_H
#define F2DUTILIES_HZST_CLIP_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"
#include "hzdt_varint_array.h"
#include "hzdt_points_array.h"
#include "hzdt_object.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeClip : public HzSemanticTypeBase {
private:
  HzDataTypeObject _beginObject;
  HzDataTypeVarintArray _contourCounts;
  HzDataTypePointsArray _points;
  HzDataTypeVarintArray _indices;
  HzDataTypeObject _endObject;
public:
  HzSemanticTypeClip();

  ~HzSemanticTypeClip() override = default;

  void pushContourCounts(uint64_t counts);

  void pushPoints(double x, double y);

  void pushIndex(uint64_t index);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_CLIP_H
