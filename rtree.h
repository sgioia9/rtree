//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_H
#define RTREE_H

#include <vector>

#include "rectangle.h"
#include "rtreenode.h"

class RTree {
  std::vector<Rectangle> find();
private:
  RTreeNode* rtree;
};

#endif //RTREE_H
