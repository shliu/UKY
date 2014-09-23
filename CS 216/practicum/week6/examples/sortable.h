#ifndef SORTABLE_H
#define SORTABLE_H 

#include <sort/sortablebase.h>
#include <vector>

class Sortable : public sort::SortableBase{
public:
  Sortable(const std::vector<int> & data) : sort::SortableBase(data){};
  void qsort();
  void stlsort();
};


class DescendingComparer{
public:
  bool operator()(const int& x, const int& y) const;
};

#endif


