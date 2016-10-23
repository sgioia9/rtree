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

ostream& operator<<(ostream& out, const RTree& other) {
  out << other.id << " "
      << other.children.size() << " "
      << other.has_leaf_children << " "
      << other.id_parent << std::endl;
  for (const Rectangle& rectangle : other.children) {
    out << rectangle << std::endl;
  }
}
