//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZ_TYPE_BASE_H
#define F2DUTILIES_HZ_TYPE_BASE_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"

BEGIN_HZ_F2D_NAMESPACE

class HzTypeBase {
protected:
  HzF2dDataType _dataType;
  HzF2dSemanticType _semanticType;

public:
  explicit HzTypeBase(const HzF2dDataType dataType,
                      const HzF2dSemanticType semanticType)
      : _dataType(dataType), _semanticType(semanticType) {}

  virtual ~HzTypeBase() = default;

  virtual void flush(std::ofstream &output) = 0;
};

END_NAMESPACE

#endif // F2DUTILIES_HZ_TYPE_BASE_H
