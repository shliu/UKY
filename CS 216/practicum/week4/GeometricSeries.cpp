#include "GeometricSeries.h"
#include <cmath>
#include <limits>

GeometricSeries::GeometricSeries(double ratio):ratio(ratio){}

double GeometricSeries::psum(const unsigned long n) const{
  double sum = 0.0;
  for( int i = 0; i <= n; i++ )
    sum += std::pow( ratio, i );
  return sum;
}

double GeometricSeries::limit() const{
  if( ratio == -1 )
    return std::numeric_limits<double>::infinity();
  else if( ratio >= 1 || ratio < -1 )
    return std::numeric_limits<double>::quiet_NaN();
  else{
    return 1/(1-ratio);
  }
}
