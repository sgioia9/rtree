#include "rectangle.h"

int Rectangle::area() {
  return abs(x2 - x1) * abs(y2 - y1);
}

bool Rectangle::intersects(Rectangle& other) {
  return isContained(other.x1, other.y1) || isContained(other.x1, other.y2)
         || isContained(other.x2, other.y1) || isContained(other.x2, other.y2);
}

bool Rectangle::isContained(int x, int y) {
  return x >= x1 && x <= x2 && y <= y1 && y >= y2;
}

ostream& operator<<(ostream& out, const Rectangle& other) {
  return out << other.id << " "
             << other.x1 << " "
             << other.y1 << " "
             << other.x2 << " "
             << other.y2;
}