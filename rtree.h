//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_H
#define RTREE_H

#include <vector>

#include "rectangle.h"
#include "rtreenode.h"

class RTree {
  friend class LinearSplit;
public:
  RTree(int m, int M) : m(m), M(M) { }
  std::vector<int> find(const std::string& tree_directory,
                        const Rectangle& rectangle);

  void setRootId(int id);
private:
  RTreeNode* current_tree_node;
  int root_id;
  int total_node_count = 0;
  int m, M;
};

#endif //RTREE_H
