//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_H
#define RTREE_H

#include <vector>

#include "rectangle.h"
#include "rtreenode.h"
#include "split.h"


class RTree {
  friend class LinearSplit;
public:
  RTree(int m, int M, Split* split, const std::string& tree_directory);
  void find(const Rectangle rectangle);
  void insert(Rectangle rectangle);
private:
  RTreeNode* current_tree_node;
  Split* split_method;
  int root_id;
  int total_node_count = 0;
  int m, M;
  std::string tree_directory;
};

#endif //RTREE_H
