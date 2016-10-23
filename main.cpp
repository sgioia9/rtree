#include <iostream>

#include "rtreenode.h"

int main(int argc, char const *argv[]) {

  /*
  RTreeNode tree(1, 0);
  tree.addRectangle(Rectangle(2, 10, 20, 30, 40));
  tree.addRectangle(Rectangle(3, 15, 25, 100, 200));
  tree.addRectangle(Rectangle(4, 19, 30, 100, 150));
  tree.writeToDisk();
   */
  RTreeNode tree = RTreeNode::readFromDisk(1);
  return 0;
}