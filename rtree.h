//
// Created by stefano on 23-10-16.
//

#ifndef RTREE_H
#define RTREE_H

#include <vector>

#include "rectangle.h"
#include "rtreenode.h"

class RTree {
public:
  std::vector<int> find(const std::string& tree_directory,
                        const Rectangle& rectangle);

  void setRootId(int id);
private:
  RTreeNode* current_tree_node;
  int root_id;
};

#endif //RTREE_H
