#include "namemodel.h"
#include <string>

//NameModel::NameModel( QObject* o ){};

void NameModel::setName(const std::string f, const std::string l){
  m_f = f;
  m_l = l;
  emit nameChanged();
  }

std::string NameModel::first() const{
  return m_f;
  }

std::string NameModel::last() const{
  return m_l;
  }
