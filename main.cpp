#include <iostream>

#include "rtreenode.h"
#include "rtree.h"

using namespace std;

int main(int argc, char const *argv[]) {

  /*
  RTreeNode tree(1, 0);
  tree.addRectangle(Rectangle(2, 10, 20, 30, 40));
  tree.addRectangle(Rectangle(3, 15, 25, 100, 200));
  tree.addRectangle(Rectangle(4, 19, 30, 100, 150));
  tree.writeToDisk();
   */
  RTree rtree;
  rtree.setRootId(1);
  std::vector<int> results = rtree.find(Rectangle(1, -50, 5, 20, -5));
  for (int result : results) {
    std::cout << result << std::endl;
  }
  return 0;
}