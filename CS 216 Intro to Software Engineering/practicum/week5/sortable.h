#ifndef SORTABLE_H
#define SORTABLE_H 

#include "sortablebase.h"
#include <vector>

class Sortable : public SortableBase{
public:
  Sortable(const std::vector<int> & data) : SortableBase(data){};
  void qsort();
  void stlsort();
};


class DescendingComparer{
public:
  bool operator()(const int& x, const int& y) const;
};

#endif


