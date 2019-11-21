//
// Created by rasefon on 2019/1/18.
//
#include "../include/hz_stream_utils.h"
#include <math.h>

void hzf2d::HzStreamUtils::convPushVarints(std::ofstream &output,
                                           uint64_t data) {
  short shift = 0;
  char value = 0;
  bool more = true;
  while (true) {
    value = static_cast<char>((data >> shift) & 0x7f);
    if ((data >> shift) > 0x7f) {
      shift += 7;
      value |= 0x80;
    } else {
      more = false;
    }

    output.write(&value, sizeof(char));
    if (!more) {
      break;
    }
  }
}

void hzf2d::HzStreamUtils::convPushPoint(std::ofstream &output, double position,
                                         long double lastPosition, long double scale) {
  SOFT_ASSERT(scale > 0);

  long double residual = position - lastPosition;
  long double storeValue = fabs(residual) * scale;
  //  double storeValue = fabs(position) / scale;
  uint64_t data = static_cast<uint64_t>(storeValue);
  data = (data << 1);
  if (residual < 0.0) {
    //  if (position < 0.0) {
    data |= 1;
  }

  convPushVarints(output, data);
}

void hzf2d::HzStreamUtils::convPushUint8(std::ofstream &output, uint8_t data) {
  char value = data;

  output.write(&value, sizeof(char));
}

void hzf2d::HzStreamUtils::convPushUint16(std::ofstream &output,
                                          uint16_t data) {
  char value = 0;
  short shift = 0;
  for (int i = 0; i < 2; ++i, shift += 8) {
    value = static_cast<char>((data >> shift) & 0xff);
    output.write(&value, sizeof(char));
  }
}

void hzf2d::HzStreamUtils::convPushUint32(std::ofstream &output,
                                          uint32_t data) {
  char value = 0;
  short shift = 0;
  for (int i = 0; i < 4; ++i, shift += 8) {
    value = static_cast<char>((data >> shift) & 0xff);
    output.write(&value, sizeof(char));
  }
}

void hzf2d::HzStreamUtils::convPushFloat(std::ofstream &output, float data) {
  char value = 0;
  uint8_t bData[4];
  memcpy(bData, &data, sizeof(data));
  for (uint8_t i : bData) {
    value = static_cast<char>(i);
    output.write(&value, sizeof(char));
  }
}

void hzf2d::HzStreamUtils::convPushDouble(std::ofstream &output, double data) {
  char value = 0;
  uint8_t bData[8];
  memcpy(bData, &data, sizeof(data));
  for (uint8_t i : bData) {
    value = static_cast<char>(i);
    output.write(&value, sizeof(char));
  }
}

void hzf2d::HzStreamUtils::convPushString(std::ofstream &output,
                                          const std::string &data) {
  output << data;
}

void hzf2d::HzStreamUtils::writeHeader(std::ofstream &output,
                                       const std::string &minorVersion) {
  convPushString(output, "F2D");
  convPushString(output, "01");
  convPushString(output, ".");
  convPushString(output, minorVersion);
}

void hzf2d::HzStreamUtils::writeDataType(std::ofstream &output,
                                         hzf2d::HzF2dDataType &dataType) {
  convPushVarints(output, dataType);
}

void hzf2d::HzStreamUtils::writeSemanticType(
    std::ofstream &output, hzf2d::HzF2dSemanticType &semanticType) {
  convPushVarints(output, semanticType);
}
