#include <ostream>
#include <vector>

#ifndef RTREE_RECTANGLE_H
#define RTREE_RECTANGLE_H

using std::ostream;
class Rectangle {
  friend class RTree;
  friend class RTreeNode;
  friend class LinearSplit;
public:
  Rectangle(int x1, int y1, int x2, int y2) : Rectangle(-1, x1, y1, x2, y2) { }
  Rectangle(int id, int x1, int y1, int x2, int y2)
          : x1(x1), y1(y1), x2(x2), y2(y2), id(id) { }
  Rectangle(const Rectangle& other);
  static Rectangle mbr(const std::vector<Rectangle>& rectangles) const;
  static Rectangle mbr(const Rectangle& r1, const Rectangle& r2) const;
  int area();
  bool intersects(const Rectangle& other) const;
  bool operator==(const Rectangle& other) const;
  friend ostream& operator<<(ostream& out, const Rectangle& other);

private:
  int x1, y1, x2, y2, id;
};

#endif //RTREE_RECTANGLE_H
