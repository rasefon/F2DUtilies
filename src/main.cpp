//
// Created by rasefon on 2019/1/18.
//

#include <codecvt>
#include <iostream>
#include <string>

#include "../public/include/hz_f2d_exporter.h"

void testExporter() {

  hzf2d::HzF2dExporter exporter("/Users/rasefon/Desktop/f2d-node/data/f2dtt",
                                0.0000635, 0.0000635);
  exporter.beginSheet(4294967295);

  exporter.setLineWeight(1);
  exporter.setMiterAngle(0.1745329350233078f);
  exporter.setMiterLength(6);
  std::vector<double> transform({551.5628893493689, 0, 0, 0, 0,
                                 551.5628893493689, 0, 0, 0, 0, 1, 0,
                                 -854808.3906683336, -731551.1932672242, 0, 1});
  exporter.setViewPort("inches", transform);
  std::vector<double> clipPoints(
      {0, 0, 0, 297, 419.99999999999994, 297, 419.99999999999994, 0});
  std::vector<uint64_t> clipIndices({0, 1, 3, 1, 2, 3});
  exporter.pushClip(4, clipPoints, clipIndices);
  exporter.setLayer(1);

  exporter.beginObject(65);
  std::vector<double> polylines1({188.95579354053007, 131.67128304641881,
                                  187.02946014947668, 131.14591939431386});
  exporter.pushPolylines(polylines1);

  exporter.beginObject(145);
  std::vector<double> polylines2({187.02946014947668, 131.14591939431352,
                                  188.95579354053007, 131.14591939431352,
                                  188.95579354053007, 131.67128304641881,
                                  187.02946014947668, 131.67128304641881,
                                  187.02946014947668, 131.14591939431352});
  exporter.pushPolylines(polylines2);

  exporter.endSheet();
  exporter.writeToFile();
}

int main(int argc, char **argv) {
  testExporter();
  return 0;
}