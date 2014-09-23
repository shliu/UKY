#ifndef PLAN_H
#define PLAN_H

#include <string>

#include <QDomElement>


class Plan{
public:
  virtual ~Plan(){};
  
  void print() const;
  
  virtual std::string type() const = 0;
  virtual unsigned int account() const = 0;
  virtual unsigned int rate() const = 0;
  virtual std::string rateUnit() const = 0;
  virtual unsigned int usage() const = 0;
  virtual std::string usageUnit() const = 0;
  virtual unsigned int subtotal() const = 0;
}; // class Plan

#endif