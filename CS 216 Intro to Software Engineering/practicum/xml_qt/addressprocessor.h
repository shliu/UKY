#ifndef PROCESSING_H
#define PROCESSING_H

#include "address.h"
#include <exception>
#include <vector>
#include <QString>

class AddressProcessor{
public:
  AddressProcessor(const QString& infile);
  void print() const;

  class Exception : public std::exception{
  private:
    const char* m_msg;
  public:
    Exception(const char* msg) : m_msg(msg){};
    virtual const char * what() const throw() {return m_msg;};
  };
private:
  std::vector<Address> nodes;

};


#endif
