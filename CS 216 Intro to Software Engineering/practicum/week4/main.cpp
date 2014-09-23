#include <iostream>
#include <sys/time.h>
#include "GeometricSeries.h"

inline double time_now(const timeval & now){
  return now.tv_sec + now.tv_usec/1000000.0;
}


int main(){
  using namespace std;

  timeval now;
  double ratio, start, end;
  unsigned long n;

  cout << "Please enter the ratio: ";
  cin >> ratio; 
  GeometricSeries MySeries(ratio);
  cout << "Enter n value: ";
  cin >> n;

  gettimeofday(&now, NULL);
  start = time_now( now );
  cout << endl 
    << "Partial Sum: " << MySeries.psum(n) << endl 
    << "Limit:       " << MySeries.limit() << endl;
  gettimeofday(&now, NULL);
  end = time_now( now );
  cout << "Elapsed: " << end - start << endl; 
  return 0;
}
