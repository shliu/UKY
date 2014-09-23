#ifndef CIRCLEFACTORY_H
#define CIRCLEFACTORY_H

#include "shapefactory.h"
#include "circle.h"

class CircleFactory : public ShapeFactory {
public:
  CircleFactory();
  virtual Circle* createShape(const QDomElement& element) const;
};

#endif
