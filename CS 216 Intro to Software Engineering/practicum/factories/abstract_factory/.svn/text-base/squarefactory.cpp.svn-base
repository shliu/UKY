#include "squarefactory.h"

#include <cassert>

static SquareFactory squareFactory;

SquareFactory::SquareFactory() {
  ShapeFactory::registerShape("square", this);
}

Square* SquareFactory::createShape(const QDomElement& element) const {
  assert(!element.isNull());
  assert(element.tagName()=="square");
  
  Square* square = new Square(element);
  
  return square;
}