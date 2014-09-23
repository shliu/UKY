#include "point.h"

#include <cmath>

Point::Point(const double& x, const double& y) : m_x(x), m_y(y) {}

double
Point::distanceTo(const Point &point) const {
  const double distance = 
    std::sqrt((m_x-point.m_x)*(m_x-point.m_x)+(m_y-point.m_y)*(m_y-point.m_y));
  return distance;
}
