#include "rectanglefactory.h"

#include <cassert>

static RectangleFactory rectangleFactory;

RectangleFactory::RectangleFactory() {
  ShapeFactory::registerShape("rectangle", this);
}

Rectangle* RectangleFactory::createShape(const QDomElement& element) const {
  assert(!element.isNull());
  assert(element.tagName()=="rectangle");
  
  Rectangle* rectangle = new Rectangle(element);
    
  return rectangle;
}