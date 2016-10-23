#include <ostream>

#ifndef RTREE_RECTANGLE_H
#define RTREE_RECTANGLE_H

using std::ostream;
class Rectangle {
public:
  Rectangle(int id, int x1, int y1, int x2, int y2)
          : x1(x1), y1(y1), x2(x2), y2(y2), id(id) { }
  int area();
  bool isContained(int x, int y);
  bool intersects(Rectangle& other);
  friend ostream& operator<<(ostream& out, const Rectangle& other);

private:
  int x1, y1, x2, y2, id;
};

#endif //RTREE_RECTANGLE_H
