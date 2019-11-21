//
// Created by rasefon on 2019/1/23.
//

#include "../include/hzst_object_id.h"
#include "../include/hz_points_transformer.h"

hzf2d::HzSemanticTypeObjectId::HzSemanticTypeObjectId(uint64_t objectId)
    : _objectId(st_object_id, objectId) {}

void hzf2d::HzSemanticTypeObjectId::flush(std::ofstream &output) {
  HzPointsTransformer &pt = HzPointsTransformer::instance();
  pt.updateLastPoint(0, 0);
  _objectId.flush(output);
}
