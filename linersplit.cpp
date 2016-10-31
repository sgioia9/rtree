//
// Created by stefano on 23-10-16.
//

#include "linearsplit.h"

void LinearSplit::split(const std::vector<Rectangle> &source,
                        std::vector<Rectangle> &firstSplit,
                        std::vector<Rectangle> &secondSplit) {
  Rectangle mbr = Rectangle::mbr(source);
  std::vector<Rectangle> extremes = get_extreme_rects(source);
  Rectangle topY = extremes[2];
  Rectangle bottomY = extremes[3];
  Rectangle leftX = extremes[0];
  Rectangle rightX = extremes[1];

  float horizontal_separation = 1.0f * (rightX.x1 - leftX.x2) / (mbr.x2 - mbr.x1);
  float vertical_separation = 1.0f * (topY.y2 - bottomY.y1) / (mbr.y1 - mbr.y2);
  if (horizontal_separation < vertical_separation) {
    firstSplit.push_back(leftX);
    secondSplit.push_back(rightX);
  } else {
    firstSplit.push_back(topY);
    secondSplit.push_back(bottomY);
  }
  Rectangle first_mbr = firstSplit[0];
  Rectangle second_mbr = secondSplit[0];
  for (const Rectangle& rectangle : source) {
    if (rectangle == firstSplit[0] || rectangle == secondSplit[0]) continue;
    Rectangle first_candidate = Rectangle::mbr(first_mbr, rectangle);
    Rectangle second_candidate = Rectangle::mbr(second_mbr, rectangle);
    if (first_candidate.area() - first_mbr.area()
        < second_candidate.area() - second_mbr.area()) {
      firstSplit.push_back(rectangle);
      first_mbr = Rectangle::mbr(first_mbr, first_candidate);
    } else {
      secondSplit.push_back(rectangle);
      second_mbr = Rectangle::mbr(second_mbr, second_candidate);
    }
  }
  while (firstSplit.size() < rtree->m && !secondSplit.empty()) {
    firstSplit.push_back(secondSplit.back());
    secondSplit.pop_back();
  }
  while (secondSplit.size() < rtree->m && !firstSplit.empty()) {
    secondSplit.push_back(firstSplit.back());
    firstSplit.pop_back();
  }
}