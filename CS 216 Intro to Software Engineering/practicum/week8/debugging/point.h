#ifndef POINT_H
#define POINT_H

class Point {
public:
  Point(const double& x=0.0, const double& y=0.0);
  double distanceTo(const Point& point) const;
  double distanceToOrigin() const;
  bool biggerThan(const double value) const{
	return (m_x > value || m_y > value);
  }
  double x() const {return m_x;}
  double y() const {return m_y;}
private:
  double m_x;
  double m_y;
}; // class Point

#endif
