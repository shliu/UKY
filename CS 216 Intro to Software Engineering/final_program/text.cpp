#include "text.h"

#include <cassert>


Text::Text(const QDomElement& element){
  m_type = element.tagName().toStdString();
  assert(m_type=="text");

  QDomElement e;
  
  e = element.namedItem("accountnumber").toElement();
  m_account_num = e.text().toUInt();
  assert(m_account_num>0);
  
  e = element.namedItem("rate").toElement();
  m_rate = e.text().toUInt();
  assert(m_rate>=0);
  
  e = element.namedItem("usage").toElement();
  m_usage = e.text().toUInt();
  assert(m_usage>=0);
}


std::string Text::type() const{
  return m_type;
}

unsigned int Text::account() const{
  return m_account_num;
}

unsigned int Text::subtotal() const{
  return m_rate * m_usage;
}

unsigned int Text::rate() const{
  return m_rate;
}

std::string Text::rateUnit() const{
  return "Cents";
}

unsigned int Text::usage() const{
  return m_usage;
}

std::string Text::usageUnit() const{
  return "Messages";
}