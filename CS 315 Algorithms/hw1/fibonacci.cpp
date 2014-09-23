#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

void print_time();
long fib1(int n);
long fib2(int n);

int main()
{
	const int max = 64;
	for(int i=0; i<=64; i++)
	{
		print_time();
		cout << "Fib2(" << i << ") = " << fib2(i) << endl;
	}	
	print_time();
	return 0;
}


void print_time()
{
	time_t now = time(NULL);
	struct tm* tm = localtime(&now);
	printf("The current time is: %d:%d:%d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
}



long fib1(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib1(n-1) + fib1(n-2);
}


long fib2(int n)
{
	if(n==0)
		return 0;

	long array[n];
	array[0]=0;
	array[1]=1;
	
	for(int i=2; i<=n; i++)
	{
		array[i] = array[i-1] + array[i-2];
	}	

	return array[n];
}
