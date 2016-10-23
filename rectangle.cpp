#include "rectangle.h"

int Rectangle::area() {
  return abs(x2 - x1) * abs(y2 - y1);
}

bool Rectangle::intersects(const Rectangle& other) const {
  return !(other.y2 > y1 || other.y1 < y2 ||
      other.x1 > x2 || other.x2 < x1);
}

ostream& operator<<(ostream& out, const Rectangle& other) {
  return out << other.id << " "
             << other.x1 << " "
             << other.y1 << " "
             << other.x2 << " "
             << other.y2;
}