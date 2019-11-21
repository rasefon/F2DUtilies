//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_TEXT_H
#define F2DUTILIES_HZST_TEXT_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "../public/include/hzst_base.h"
#include "hz_type_base.h"
#include "hzdt_float.h"
#include "hzdt_object.h"
#include "hzdt_point.h"
#include "hzdt_string.h"
#include "hzdt_varint.h"
#include "hzdt_varint_array.h"
#include "hzst_polytriangle.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeText : public HzSemanticTypeBase {
private:
  HzDataTypeObject _beginObject;
  HzDataTypeString _str;
  HzDataTypePoint _position;
  HzDataTypeVarint _height;
  HzDataTypeFloat _widthScale;
  HzDataTypeFloat _rotation;
  HzDataTypeFloat _oblique;
  HzDataTypeVarintArray _charWidths;
  HzSemanticTypePolytriangle _polytriangle;
  HzDataTypeObject _endObject;

public:
  HzSemanticTypeText(const std::string &str, double x, double y,
                     uint64_t height, float widthScale, float rotation,
                     float oblique,
                     const HzSemanticTypePolytriangle &polytriangle);

  ~HzSemanticTypeText() override = default;

  void flush(std::ofstream &output) override;

  void pushCharWidth(uint64_t value);
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_TEXT_H
