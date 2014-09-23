#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QDomElement>

#include "shape.h"

class Triangle : public Shape {
public:
  Triangle(const double& base, const double& height)
    : m_base(base), m_height(height) {}
  Triangle(const QDomElement& element);
  virtual double area() const {return m_base * m_height / 2;}
private:
  double m_base, m_height;
};

#endif
