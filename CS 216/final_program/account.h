#ifndef ACCOUNT_H
#define ACCOUNT_H 

#include <QDomNode>
#include <QString>

class Account{
public:
  Account(const QDomNode & node);
  void print() const;
  unsigned int number() const;
private:
  //data members of the account
  unsigned int m_account_num;
  QString m_phone_num;
  QString m_fname;
  QString m_lname;
  QString m_street;
  QString m_city;
  QString m_state;
  QString m_zip;
};

#endif
