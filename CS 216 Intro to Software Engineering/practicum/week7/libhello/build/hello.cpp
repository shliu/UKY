#include "hello.h"

  static const std::string hello_version = "1.0\n$Id: hello.cpp.in 7 2011-10-05 18:51:01Z shliu2 $";

  Hello::Hello(const std::string& message) : m_message(message) {}
  std::string Hello::message() const {return m_message;}
  std::string Hello::version() {return hello_version;}
