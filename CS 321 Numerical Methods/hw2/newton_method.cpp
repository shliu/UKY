#include <iostream>
#include <math.h>
using namespace std;


double newton(double x)
{
	double x_next;
	
	x_next = ( pow(x,2) - 2*pow(x,3) - 1) / ( 1 + 2*x - 3*pow(x,2) );
	
	return x_next;
}


int main()
{
	int interations = 5;
	double x = 1.5;
	cout.precision(15);
	
	cout << "x0: " << fixed << x << endl;
	for(int i = 0; i < interations; ++i)
	{
		x = newton(x);
		cout << "x" <<  i + 1 << ": " << fixed << x << endl;
	}
	
	return 0;
}

