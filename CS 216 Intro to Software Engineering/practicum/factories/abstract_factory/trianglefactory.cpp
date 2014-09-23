#include "trianglefactory.h"

#include <cassert>

static TriangleFactory triangleFactory;

TriangleFactory::TriangleFactory(){
  ShapeFactory::registerShape("triangle", this);
}

Triangle* TriangleFactory::createShape(const QDomElement& element) const{
  assert(!element.isNull());
  assert(element.tagName()=="triangle");

  Triangle* triangle = new Triangle(element);

  return triangle;
}
