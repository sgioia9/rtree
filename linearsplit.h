//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_LINEARSPLIT_H
#define RTREE_LINEARSPLIT_H

#include "split.h"

class LinearSplit : public Split {
public:
  LinearSplit(int m, int M) : Split(m, M) { }

  virtual void split(const std::vector<Rectangle> &source,
                     std::vector<Rectangle> &firstSplit,
                     std::vector<Rectangle> &secondSplit) override;
};

#endif //RTREE_LINEARSPLIT_H
