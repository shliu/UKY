#include "triangle.h"

#include <cassert>

Triangle::Triangle(const QDomElement& element){
  QDomElement base = element.namedItem("base").toElement();
  assert(!base.isNull());
  m_base = base.text().toDouble();
  assert(m_base>0.0);

  QDomElement height = element.namedItem("height").toElement();
  assert(!height.isNull());
  m_height = height.text().toDouble();
  assert(m_height>0.0);
}
