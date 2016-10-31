//
// Created by Geno on 30-Oct-16.
//

#include "greeneSplit.h"
void GreeneSplit::split(const std::vector<Rectangle> &source,
                        std::vector<Rectangle> &firstSplit,
                        std::vector<Rectangle> &secondSplit) {
  std::vector<Rectangle> source_cpy;
  for(int i = 0 ; i < source.size(); i++){
    source_cpy.push_back(source[i]);
  }
  Rectangle mbr = Rectangle::mbr(source);
  std::vector<Rectangle> extremes = get_extreme_rects(source);
  float horizontal_separation = 1.0f * (extremes[1].x1 - extremes[0].x2) / (mbr.x2 - mbr.x1);
  float vertical_separation = 1.0f * (extremes[2].y2 - extremes[3].y1) / (mbr.y1 - mbr.y2);
  if(horizontal_separation < vertical_separation){
    std::sort(source_cpy.begin(),source_cpy.end(),cmp_y);
  } else {
    std::sort(source_cpy.begin(),source_cpy.end(),cmp_x);
  }
  for(int i = 0 ; i < source_cpy.size(); i++){
    if(i < source_cpy.size()/2) firstSplit.push_back(source_cpy[i]);
    else secondSplit.push_back(source_cpy[i]);
  }


}

bool GreeneSplit::cmp_x(const Rectangle &rect1, const Rectangle &rect2) {
  return rect1.x1 < rect2.x1;
}

bool GreeneSplit::cmp_y(const Rectangle &rect1, const Rectangle &rect2) {
  return rect1.y2 < rect2.y2;
}

