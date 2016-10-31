//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_SPLIT_H
#define RTREE_SPLIT_H

#include <vector>

#include "rectangle.h"
#include "rtree.h"

class Split {

public:
  static const int INF = int(1e9);

  Split(RTree* rtree) : rtree(rtree) { }

    std::vector<Rectangle> get_extreme_rects(const std::vector<Rectangle> &source);

    virtual void split(const std::vector<Rectangle>& source,
             std::vector<Rectangle>& firstSplit,
             std::vector<Rectangle>& secondSplit) = 0;
protected:
  RTree* rtree;
};

#endif //RTREE_SPLIT_H
