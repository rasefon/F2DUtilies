//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_VIEWPORT_H
#define F2DUTILIES_HZST_VIEWPORT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "hzdt_double_array.h"
#include "hzdt_object.h"
#include "hzdt_string.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeViewPort : public HzSemanticTypeBase {
private:
  HzDataTypeObject _beginObject;
  HzDataTypeString _units;
  HzDataTypeDoubleArray _transform;
  HzDataTypeObject _endObject;

public:
  HzSemanticTypeViewPort(const std::string &units, const std::vector<double> &transform);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_VIEWPORT_H
