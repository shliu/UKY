#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"
#include "point.h"

class Rectangle : public Polygon {
public:
  Rectangle(const Point& p0, const Point& p1);
  virtual int numberOfPoints() const { return 4; }
  virtual Point point(const int& index) const;
  virtual double circumference() const;
private:
  // lower left corner point
  Point m_p0;
  // upper right corner point
  Point m_p1;
}; // class Rectangle

#endif