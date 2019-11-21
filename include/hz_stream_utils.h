//
// Created by rasefon on 2019/1/18.
//
#ifndef HZ_F2D_STREAM_UTILS_H
#define HZ_F2D_STREAM_UTILS_H

#include <fstream>
#include <iostream>

#include "../public/include/hz_f2d_common.h"
#include "../public/include/hz_f2d_macros.h"

BEGIN_HZ_F2D_NAMESPACE

class HzStreamUtils {
public:
  static void convPushVarints(std::ofstream &output, uint64_t data);

  static void convPushPoint(std::ofstream &output, double position,
                            long double lastPosition, long double scale);

  static void convPushUint8(std::ofstream &output, uint8_t data);

  static void convPushUint16(std::ofstream &output, uint16_t data);

  static void convPushUint32(std::ofstream &output, uint32_t data);

  static void convPushFloat(std::ofstream &output, float data);

  static void convPushDouble(std::ofstream &output, double data);

  static void convPushString(std::ofstream &output, const std::string &data);

  static void writeHeader(std::ofstream &output,
                          const std::string &minorVersion);

  static void writeDataType(std::ofstream &output, HzF2dDataType &dataType);

  static void writeSemanticType(std::ofstream &output,
                                HzF2dSemanticType &semanticType);
};

END_NAMESPACE

#endif // HZ_F2D_STREAM_UTILS_H
