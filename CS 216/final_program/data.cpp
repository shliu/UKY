#include "data.h"

#include <cassert>


Data::Data(const QDomElement& element){
  m_type = element.tagName().toStdString();
  assert(m_type=="data");

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


std::string Data::type() const{
  return m_type;
}

unsigned int Data::account() const{
  return m_account_num;
}

unsigned int Data::subtotal() const{
  return m_rate * m_usage;
}

unsigned int Data::rate() const{
  return m_rate;
}

std::string Data::rateUnit() const{
  return "Cents";
}

unsigned int Data::usage() const{
  return m_usage;
}

std::string Data::usageUnit() const{
  return "Megabytes";
}