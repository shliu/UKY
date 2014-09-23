#include "textfactory.h"

#include <cassert>

Text* TextFactory::createShape(const QDomElement& element){
  assert(!element.isNull());
  assert(element.tagName()=="text");
  
  Text* text = new Text(element);
  
  return text;
}