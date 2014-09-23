#include "sortablebase.h"

#include <cassert>
#include <iostream>

SortableBase::SortableBase(const std::vector<int>& data) :
m_data(data) {assert(!data.empty());}

void SortableBase::printFirst(const unsigned long& number) const{
  assert(number<=m_data.size());
  for(size_t i=0; i<number; ++i)
    std::cout << m_data[i] << ' ';
  std::cout << std::endl;
}

void SortableBase::printLast(const unsigned long& number) const {
  assert(number<=m_data.size());
  for(size_t i=m_data.size()-1; i>=m_data.size()-number; --i)
    std::cout << m_data[i] << ' ';
  std::cout << std::endl;
}
