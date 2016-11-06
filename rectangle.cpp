#include "rectangle.h"

Rectangle::Rectangle(const Rectangle &other) {
  id = other.id;
  x1 = other.x1;
  x2 = other.x2;
  y1 = other.y1;
  y2 = other.y2;
}

Rectangle Rectangle::mbr(const std::vector<Rectangle> &rectangles){
  float minX = Rectangle::INF;
  float maxX = -Rectangle::INF;
  float minY = Rectangle::INF;
  float maxY = -Rectangle::INF;
  for (const Rectangle& rectangle : rectangles) {
    minX = std::min(minX, rectangle.x1);
    minY = std::min(minY, rectangle.y2);
    maxX = std::max(maxX, rectangle.x2);
    maxY = std::max(maxY, rectangle.y1);
  }
  return Rectangle(minX, maxY, maxX, minY);
}

Rectangle Rectangle::mbr(const Rectangle& r1, const Rectangle& r2){
  std::vector<Rectangle> rectangles;
  rectangles.push_back(r1);
  rectangles.push_back(r2);
  return Rectangle::mbr(rectangles);
}

double Rectangle::area() const {
  return abs(x2 - x1) * abs(y2 - y1);
}

bool Rectangle::intersects(const Rectangle& other) const {
  return !(other.y2 > y1 || other.y1 < y2 ||
      other.x1 > x2 || other.x2 < x1);
}


ostream& operator<<(ostream& out, const Rectangle& other) {
  return out << std::fixed << other.id << " "
                           << other.x1 << " "
                           << other.y1 << " "
                           << other.x2 << " "
                           << other.y2;
}


bool Rectangle::operator==(const Rectangle &other) const {
  return x1 == other.x1 && x2 == other.x2 && y1 == other.y1 && y2 == other.y2;
}