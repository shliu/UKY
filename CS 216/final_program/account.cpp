#include "account.h"

#include <iostream>

Account::Account(const QDomNode & node){
  //store node's data into class data members
  QDomElement e;
  
  e = node.namedItem("accountnumber").toElement();
  m_account_num = e.text().toUInt();
  
  e = node.namedItem("phonenumber").toElement();
  m_phone_num = e.text();
  
  e = node.namedItem("firstname").toElement();
  m_fname = e.text();

  e = node.namedItem("lastname").toElement();
  m_lname = e.text();

  e = node.namedItem("street").toElement();
  m_street = e.text();

  e = node.namedItem("city").toElement();
  m_city = e.text();

  e = node.namedItem("state").toElement();
  m_state = e.text();

  e = node.namedItem("zip").toElement();
  m_zip = e.text();
}


void Account::print() const{
  //print datamembers of this account
  std::cout << "Account# " << m_account_num << std::endl
    << m_phone_num.toStdString() << std::endl
    << m_fname.toStdString() << " " << m_lname.toStdString() << std::endl 
    << m_street.toStdString() << std::endl
    << m_city.toStdString() << ", " << m_state.toStdString() << " "
    << m_zip.toStdString() << std::endl; 
}


unsigned int Account::number() const{
  return m_account_num;
}
