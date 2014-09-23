#include "address.h"
#include <iostream>
#include <iomanip>

Address::Address(const QDomNode & node){
  //store node's data into class data members
  QDomElement e = node.namedItem("firstname").toElement();
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
  m_zip = e.text().toUInt();
}


void Address::print() const{
  using std::cout;
  using std::endl;
  //print datamembers of this address
  cout << m_fname.toStdString() << " " << m_lname.toStdString() << endl 
    << m_street.toStdString() << endl
    << m_city.toStdString() << ", " << m_state.toStdString() << " ";
  cout << std::setfill('0') << std::setw(5) << m_zip << endl; 
}
