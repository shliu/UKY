#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

#include <QDomElement>

class Square : public Shape {
public:
  Square(const double& width) : m_width(width) {}
  Square(const QDomElement& node);
  virtual double area() const {return m_width*m_width;}
private:
  double m_width;
}; // class Square

#endif
