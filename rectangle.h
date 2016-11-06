#include <ostream>
#include <vector>

#ifndef RTREE_RECTANGLE_H
#define RTREE_RECTANGLE_H

using std::ostream;
class Rectangle {
  friend class RTree;
  friend class RTreeNode;
  friend class Split;
  friend class LinearSplit;
  friend class GreeneSplit;
  static const int INF = 1e9;
  static const long long INF64 = 1e18;
public:
  Rectangle(int x1, int y1, int x2, int y2) : Rectangle(-1, float(x1), float(y1), float(x2), float(y2)) { }
  Rectangle(int id, float x1, float y1, float x2, float y2)
          : x1(x1), y1(y1), x2(x2), y2(y2), id(id) { }
  Rectangle(float x1, float y1, float x2, float y2) : Rectangle(-1, x1, y1, x2, y2) { }
  Rectangle(const Rectangle& other);
  static Rectangle mbr(const std::vector<Rectangle>& rectangles);
  static Rectangle mbr(const Rectangle& r1, const Rectangle& r2);

  double area() const;
  bool intersects(const Rectangle& other) const;
  bool operator==(const Rectangle& other) const;
  friend ostream& operator<<(ostream& out, const Rectangle& other);

private:
  float x1, y1, x2, y2;
  int id;
};

#endif //RTREE_RECTANGLE_H
