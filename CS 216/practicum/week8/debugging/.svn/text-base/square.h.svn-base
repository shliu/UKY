#ifndef SQUARE_H
#define SQUARE_H

#include "polygon.h"
#include "point.h"

class Square : public Polygon {
public:
  Square(const Point& p0, const double& width);
  virtual int numberOfPoints() const { return 4; }
  virtual Point point(const int& index) const;
  virtual double circumference() const;
private:
  // lower left corner point
  Point m_p0;
  double m_width;
}; // class Square

#endif

