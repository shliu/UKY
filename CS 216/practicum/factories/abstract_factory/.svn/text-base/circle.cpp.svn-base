#include "circle.h"

#include <cassert>

Circle::Circle(const QDomElement& element) {
  QDomElement radius = element.namedItem("radius").toElement();
  assert(!radius.isNull());
  m_radius = radius.text().toDouble();
  assert(m_radius>0.0);  
}
