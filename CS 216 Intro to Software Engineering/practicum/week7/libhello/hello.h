#ifndef LIBHELLO_H
#define LIBHELLO_H

#include <string>

class Hello {

public:
  Hello(const std::string& message);
  std::string message() const;
  static std::string version();
private:
  std::string m_message;
};

#endif
