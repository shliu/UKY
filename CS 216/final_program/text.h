#ifndef TEXT_H
#define TEXT_H

#include "plan.h"

#include <QDomElement>


class Text : public Plan {
public:
  Text(const QDomElement& element);
	
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
}; // class Text

#endif