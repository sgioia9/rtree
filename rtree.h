//
// Created by stefano on 23-10-16.
//

#include <vector>
#include <ostream>

#include "rectangle.h"

#ifndef RTREE_RTREE_H
#define RTREE_RTREE_H

class RTree {

public:
  RTree(int id, int id_parent)
          :
          id(id),
          id_parent(id_parent),
          has_leaf_children(true),
          children(std::vector<Rectangle>()) { }
  RTree(int id, int id_parent, bool has_leaf_children)
          :
          id(id),
          id_parent(id_parent),
          has_leaf_children(has_leaf_children),
          children(std::vector<Rectangle>()) { }

  static RTree readFromDisk(int tree_id);
  void addRectangle(Rectangle rectangle);
  void writeToDisk();
  friend ostream& operator<<(ostream& out, const RTree& other);
private:
  int id, id_parent;
  bool has_leaf_children;
  std::vector<Rectangle> children;
};

#endif //RTREE_RTREE_H
