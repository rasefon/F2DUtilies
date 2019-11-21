//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_FONT_DEF_H
#define F2DUTILIES_HZST_FONT_DEF_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "../public/include/hzst_base.h"
#include "hz_type_base.h"
#include "hzdt_byte_array.h"
#include "hzdt_float.h"
#include "hzdt_object.h"
#include "hzdt_string.h"
#include "hzdt_varint.h"

BEGIN_HZ_F2D_NAMESPACE

class HzSemanticTypeFontDef : public HzSemanticTypeBase {
private:
  HzDataTypeObject _beginObject;
  HzDataTypeString _name;
  HzDataTypeString _fullName;
  HzDataTypeVarint _flags;
  HzDataTypeFloat _spacing;
  HzDataTypeByteArray _panose;
  HzDataTypeObject _endObject;

public:
  explicit HzSemanticTypeFontDef(const std::string &name,
                                 const std::string &fullName, uint64_t flags,
                                 float spacing,
                                 const std::vector<uint8_t> &panose);

  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_FONT_DEF_H
