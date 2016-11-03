//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_SPLIT_H
#define RTREE_SPLIT_H

#include <vector>

#include "rectangle.h"

class Split {

public:
  Split(int m, int M) : m(m), M(M) { }

    std::vector<Rectangle> get_extreme_rects(const std::vector<Rectangle> &source);

    virtual void split(const std::vector<Rectangle>& source,
             std::vector<Rectangle>& firstSplit,
             std::vector<Rectangle>& secondSplit) = 0;
protected:
  int m;
  int M;
};

#endif //RTREE_SPLIT_H