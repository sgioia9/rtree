//
// Created by stefano on 23-10-16.
//

#include <vector>
#include <ostream>

#include "rectangle.h"

#ifndef RTREENODE_H
#define RTREENODE_H

class RTreeNode {
  friend class RTree;
public:
  RTreeNode(int id, int id_parent)
          :
          id(id),
          id_parent(id_parent),
          has_leaf_children(true),
          children(std::vector<Rectangle>()) { }
  RTreeNode(int id, int id_parent, bool has_leaf_children)
          :
          id(id),
          id_parent(id_parent),
          has_leaf_children(has_leaf_children),
          children(std::vector<Rectangle>()) { }

  static RTreeNode* readFromDisk(const std::string& tree_directory, int tree_id);
  void addRectangle(Rectangle rectangle);
  void writeToDisk();
  friend ostream& operator<<(ostream& out, const RTreeNode& other);
private:
  int id, id_parent;
  bool has_leaf_children;
  std::vector<Rectangle> children;
};

#endif //RTREENODE_H
