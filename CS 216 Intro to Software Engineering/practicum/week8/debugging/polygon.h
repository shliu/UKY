#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"

class Polygon {
public:
  virtual int numberOfPoints() const = 0;
  virtual Point point(const int& index) const = 0;
  virtual ~Polygon(){}; //needs virtual descructor for children
  virtual double circumference() const;
}; // class Polygon

#endif
