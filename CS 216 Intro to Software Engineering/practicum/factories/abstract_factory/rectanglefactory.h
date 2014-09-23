#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "shapefactory.h"
#include "rectangle.h"

class RectangleFactory : public ShapeFactory {
public:
  RectangleFactory();
  virtual Rectangle* createShape(const QDomElement& element) const;
};

#endif
