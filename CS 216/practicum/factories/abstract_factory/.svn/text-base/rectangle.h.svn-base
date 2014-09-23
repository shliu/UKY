#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QDomElement>

#include "shape.h"

class Rectangle : public Shape {
public:
  Rectangle(const double& width, const double& height) : 
    m_width(width), m_height(height) {}
  Rectangle(const QDomElement& element);
  virtual double area() const {return m_width*m_height;}
private:
  double m_width, m_height;
}; // class Rectangle

#endif
