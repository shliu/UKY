#ifndef DATA_H
#define DATA_H

#include "plan.h"

#include <QDomElement>


class Data : public Plan {
public:
  Data(const QDomElement& element);
	
  std::string type() const;
  unsigned int account() const;
  unsigned int rate() const;
  std::string rateUnit() const;
  unsigned int usage() const;
  std::string usageUnit() const;
  unsigned int subtotal() const;
private:
  std::string m_type;
  unsigned int m_account_num;
  unsigned int m_rate;
  unsigned int m_usage;
}; // class Data

#endif