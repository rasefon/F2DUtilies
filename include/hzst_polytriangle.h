//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_POLYTRIANGLE_H
#define F2DUTILIES_HZST_POLYTRIANGLE_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_int_array.h"
#include "hzdt_object.h"
#include "hzdt_points_array.h"
#include "hzdt_varint_array.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypePolytriangle : public HzSemanticTypeBase {
private:
  HzDataTypeObject _beginObject;
  HzDataTypePointsArray _points;
  HzDataTypeVarintArray _indices;
  HzDataTypeIntArray _colors;
  HzDataTypeObject _endObject;
public:
  HzSemanticTypePolytriangle();

  HzSemanticTypePolytriangle(const HzSemanticTypePolytriangle &other);

  void pushPoints(double x, double y);

  void pushIndices(uint64_t index);

  void pushColors(uint32_t color);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_POLYTRIANGLE_H
