#ifndef SORTABLEBASE_H
#define SORTABLEBASE_H

#include <vector>

class SortableBase {
public:
  void printFirst(const unsigned long& number) const;
  void printLast(const unsigned long& number) const;
protected:
  SortableBase(const std::vector<int>& data);
  std::vector<int> m_data;
};

#endif
