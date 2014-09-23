#include "rectangle.h"

#include <cassert>

Rectangle::Rectangle(const QDomElement& element) {
  QDomElement width = element.namedItem("width").toElement();
  assert(!width.isNull());
  m_width = width.text().toDouble();
  assert(m_width>0.0);
  
  QDomElement height = element.namedItem("height").toElement();
  assert(!height.isNull());
  m_height = height.text().toDouble();
  assert(m_height>0.0);
}
