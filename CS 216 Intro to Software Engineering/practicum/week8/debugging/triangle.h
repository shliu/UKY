#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"
#include "point.h"

class Triangle : public Polygon {
public:
  Triangle(const Point& p0, const Point& p1, const Point& p2);
  Triangle(const Triangle & copy);  //add copy constructor
  Triangle & operator=(const Triangle & copy); //add operator =
  ~Triangle();
  virtual int numberOfPoints() const { return 3; }
  virtual Point point(const int& index) const;
private:
  Point* m_points;
}; // class Triangle

#endif
