#include "square.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cmath>

Square::Square(const Point& p0, const double& width) 
: m_p0(p0), m_width(width) {
  assert(!(width<0.0));  //width > 0.0, !width<0.0 doesn't make sense
}

Point Square::point(const int& index) const {
  assert(index>=0);
  assert(index<4);
  switch (index) {
    case 0:
      return m_p0;
      break;
    case 1:
      return Point(m_p0.x()+m_width, m_p0.y());
      break;
    case 2:
      return Point(m_p0.x()+m_width, m_p0.y()+m_width);
      break;
    case 3:
      return Point(m_p0.x(), m_p0.y()+m_width);
      break;
    default:
      std::cerr << "invalid index\n";
      exit(EXIT_FAILURE);
      break;
  }
}

double Square::circumference() const {
  return 4.0*m_width;  //circm of square = 4.0*m_width, not 0.0*width
}
