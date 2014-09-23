#ifndef CIRCLE_H
#define CIRCLE_H

#include <QDomElement>

#include "shape.h"

class Circle : public Shape {
public:
  Circle(const double& radius) : m_radius(radius) {}
  Circle(const QDomElement& element);
  virtual double area() const {return 3.141592654*m_radius*m_radius;}
private:
  double m_radius;
}; // class Circle

#endif
