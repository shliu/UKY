#include "square.h"

#include <cassert>

Square::Square(const QDomElement& element) {
  QDomElement width = element.namedItem("width").toElement();
  assert(!width.isNull());
  m_width = width.text().toDouble();
  assert(m_width>0.0);  
}
