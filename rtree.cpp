#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "rectangle.h"
#include "rtree.h"

using std::ostream;
using std::vector;

void RTree::addRectangle(Rectangle rectangle) {
  children.push_back(rectangle);
}

void RTree::writeToDisk() {
  std::ofstream file;
  file.open(std::to_string(id) + ".rtree");
  file << *this;
  file.close();
}

RTree RTree::readFromDisk(int tree_id) {
  std::ifstream file;
  file.open(std::to_string(tree_id) + ".rtree");
  int id, id_parent, n_children;
  bool has_leaf_children;
  file >> id >> n_children >> has_leaf_children >> id_parent;
  RTree tree(id, id_parent, has_leaf_children);
  for (int i = 0; i < n_children; i++) {
    int id, x1, y1, x2, y2;
    file >> id >> x1 >> y1 >> x2 >> y2;
    tree.addRectangle(Rectangle(id, x1, y1, x2, y2));
  }
  return tree;
}

ostream& operator<<(ostream& out, const RTree& other) {
  out << other.id << " "
      << other.children.size() << " "
      << other.has_leaf_children << " "
      << other.id_parent << std::endl;
  for (const Rectangle& rectangle : other.children) {
    out << rectangle << std::endl;
  }
}
