#include "triangle.h"

#include <cassert>

Triangle::Triangle(const Point& p0, const Point& p1, const Point& p2) {
  m_points = new Point[3];
  m_points[0] = p0;
  m_points[1] = p1;
  m_points[2] = p2;
}

//requires a copy constructor because this class has a dynamic variable
//as well, during implementation uses copy by value instead of by reference
Triangle::Triangle(const Triangle & copy){
  m_points = new Point[3];
  m_points[0] = copy.m_points[0];
  m_points[1] = copy.m_points[1];
  m_points[2] = copy.m_points[2];
}

//could use an assignment operator as well, just in case we wanted to
//use = operator
Triangle & Triangle::operator=(const Triangle & copy){
  if(&copy != this){
    delete[] m_points;
    m_points = new Point[3];
    m_points[0] = copy.m_points[0];
    m_points[1] = copy.m_points[1];
    m_points[2] = copy.m_points[2];
  }
  return *this;
}

Triangle::~Triangle() {
  delete[] m_points; //m_points in a dynamic array, so use appro. delete[]
}

Point Triangle::point(const int &index) const {
  assert(index>=0); //starts at 0, so >=, not >
  assert(index<3);
  return m_points[index];
}
