#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "account.h"
#include "plan.h"

#include <exception>
#include <vector>
#include <map>

#include <QString>


class Processor{
public:
  Processor(const QString& aFile, const QString& pFile);
  ~Processor();
  
  void printBills() const;
  void printReports() const;  
  void printAccount(const int& accountNum) const;
  
  class Exception : public std::exception{
    private:
      const char* m_msg;
    public:
      Exception(const char* msg) : m_msg(msg){};
      virtual const char * what() const throw() {return m_msg;};
    };
private:
  std::vector<Account> m_accounts;
  std::multimap<unsigned int, Plan*> m_plans;
};


#endif
