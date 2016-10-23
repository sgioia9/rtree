#include <iostream>
#include <cassert>

#include "rtreenode.h"
#include "rtree.h"

using namespace std;

void test1() {
  RTree rtree;
  rtree.setRootId(1);

  std::vector<int> expected;
  expected.push_back(3);
  expected.push_back(4);

  std::vector<int> results = rtree.find("case1", Rectangle(1, -50, 5, 20, -5));

  assert (results == expected);
}

void test2() {
  RTree rtree;
  rtree.setRootId(1);

  std::vector<int> expected;
  expected.push_back(5);

  std::vector<int> results = rtree.find("case2", Rectangle(1, -50, 5, 20, -5));
  assert (results == expected);

  results = rtree.find("case2", Rectangle(0, 12, 45, 30, 20));
  expected = vector<int>();
  expected.push_back(5);
  assert (results == expected);

  results = rtree.find("case2", Rectangle(0, 0, 200, 200, 0));
  expected = vector<int>();
  for (int i = 4; i <= 7; i++) {
    expected.push_back(i);
  }
  assert (results == expected);
}


int main(int argc, char const *argv[]) {

  /*
  RTreeNode tree(1, 0);
  tree.addRectangle(Rectangle(2, 10, 20, 30, 40));
  tree.addRectangle(Rectangle(3, 15, 25, 100, 200));
  tree.addRectangle(Rectangle(4, 19, 30, 100, 150));
  tree.writeToDisk();
   */
  test1();
  test2();

  return 0;
}