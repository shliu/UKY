#include <cstdlib>
#include <algorithm>
#include "sortable.h"

extern "C"
int compareDescending(const void* x, const void* y){
  const int * xx = static_cast<const int *>(x);
  const int * yy = static_cast<const int *>(y);

  if( (*xx) > (*yy) )
    return -1;
  else
    return 1;
}


inline
bool DescendingComparer::operator()(const int& x, const int& y) const{
  return x>=y;
}



void Sortable::qsort(){
  std::qsort(&m_data[0], m_data.size(), sizeof(int), compareDescending);
}



void Sortable::stlsort(){
  DescendingComparer func;
  std::sort(m_data.begin(), m_data.end(), func);
}
