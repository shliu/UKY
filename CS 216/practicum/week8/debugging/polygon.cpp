#include "polygon.h"

#include <cassert>

double Polygon::circumference() const {
  assert(numberOfPoints()>2);
  double circumference = 0.0;
  for(int i=1; i<numberOfPoints(); ++i)
    circumference += point(i-1).distanceTo(point(i));
  //does not account for distance between p0 and pn
  circumference += point(numberOfPoints()-1).distanceTo(0);
  assert(circumference>0.0);
  return circumference;
}
