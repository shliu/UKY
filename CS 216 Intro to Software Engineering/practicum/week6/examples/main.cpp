#include <iostream>
#include <vector>
#include <cstdlib>
#include <sort/timer.h>
#include "sortable.h"


int main(){
  int max;
  std::cin >> max;

  std::vector<int> my_vector;
  srand(0);
  for(int i=0; i<max; i++){
    my_vector.push_back(rand());
  }

  sort::Timer q_timer, stl_timer;
  Sortable q(my_vector), stl(my_vector);

  q_timer.start();
  q.qsort();
  q_timer.stop();

  stl_timer.start();
  stl.stlsort();
  stl_timer.stop();

  int show = 5;
  std::cout << "qsort first: ";
  q.printFirst(show);
  std::cout << "  stl first: ";
  stl.printFirst(show);
  std::cout << "qsort last: ";
  q.printLast(show);
  std::cout << "  stl last: ";
  stl.printLast(show);
  std::cout << "qsort:   " << q_timer.elapsed() << std::endl
    << "stlsort: " << stl_timer.elapsed() << std::endl
    << "speedup: " << q_timer.elapsed()/stl_timer.elapsed() << std::endl;

  return 0;
}
