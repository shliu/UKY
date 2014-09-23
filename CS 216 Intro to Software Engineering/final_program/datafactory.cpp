#include "datafactory.h"

#include <cassert>

Data* DataFactory::createShape(const QDomElement& element){
  assert(!element.isNull());
  assert(element.tagName()=="data");
  
  Data* data = new Data(element);
  
  return data;
}