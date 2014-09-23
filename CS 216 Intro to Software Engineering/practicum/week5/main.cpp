#include <iostream>
#include <vector>
#include <cstdlib>
#include "sortable.h"
#include "timer.h"


int main(){
  using namespace std;
  
  int max;
  cin >> max;

  vector<int> my_vector;
  srand(0);
  for(int i=0; i<max; i++){
    my_vector.push_back(rand());
  }

  Timer q_timer, stl_timer;
  Sortable q(my_vector), stl(my_vector);

  q_timer.start();
  q.qsort();
  q_timer.stop();

  stl_timer.start();
  stl.stlsort();
  stl_timer.stop();

  int show = 5;
  cout << "qsort first: ";
  q.printFirst(show);
  cout << "  stl first: ";
  stl.printFirst(show);
  cout << "qsort last: ";
  q.printLast(show);
  cout << "  stl last: ";
  stl.printLast(show);
  cout << "qsort:   " << q_timer.elapsed() << endl
    << "stlsort: " << stl_timer.elapsed() << endl
    << "speedup: " << q_timer.elapsed()/stl_timer.elapsed() << endl;

  return 0;
}
