#include <iostream>
#include <cassert>

#include "rtreenode.h"
#include "rtree.h"
#include "split.h"
#include "linearsplit.h"
#include "greeneSplit.h"
using namespace std;

int main(int argc, char const *argv[]) {

  int m = 2;
  int M = 5;
  GreeneSplit* split = new GreeneSplit(m, M);
  RTree tree(m, M, split, "case3");
    for (int i = 1; i <= 12; i++) {
        Rectangle r(i, i * 11 , i * 11, i);
        tree.insert(r);
    }
    tree.find(Rectangle(10,30,30,10));
  delete split;
  return 0;
}