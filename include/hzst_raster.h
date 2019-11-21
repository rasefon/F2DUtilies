//
// Created by rasefon on 2019/1/21.
//

#ifndef F2DUTILIES_HZST_RASTER_H
#define F2DUTILIES_HZST_RASTER_H

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"
#include "hz_type_base.h"
#include "../public/include/hzst_base.h"

BEGIN_HZ_F2D_NAMESPACE

//TODO: need real example to construct this struct.
class HzSemanticTypeRaster : public HzSemanticTypeBase {
public:
  void flush(std::ofstream &output) override;
};

END_NAMESPACE

#endif // F2DUTILIES_HZST_RASTER_H
