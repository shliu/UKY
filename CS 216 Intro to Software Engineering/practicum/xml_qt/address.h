#ifndef ADDRESS_H
#define ADDRESS_H 

#include <QDomNode>
#include <QString>

class Address{
public:
  Address(const QDomNode & node);
  void print() const;
private:
  //data members of the address 
  QString m_fname;
  QString m_lname;
  QString m_street;
  QString m_city;
  QString m_state;
  unsigned int m_zip;
};

#endif
