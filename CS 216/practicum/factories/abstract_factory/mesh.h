#ifndef MESH_H
#define MESH_H

#include <QString>

#include <vector>

#include "shape.h"

class Mesh {
public:
  
  class Exception : public std::exception{
  private:
    const char* m_msg;
  public:
    Exception(const char* msg) : m_msg(msg) {}
    virtual const char * what() const throw() {return m_msg;}
  }; // class Exception
  
  Mesh(const QString& filename);
  ~Mesh();
  void process() const;
private:
  std::vector<Shape*> m_shapes;
};

#endif
