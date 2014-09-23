#ifndef GeometricSeries_H
#define GeometricSeries_H

class GeometricSeries{
private:
  double ratio;
public:
  GeometricSeries(double ratio);
  double psum(const unsigned long n) const;
  double limit() const;
};


#endif
