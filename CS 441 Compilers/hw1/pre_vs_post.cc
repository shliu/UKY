#include <iostream>
using namespace std;

int main()
{
	//i-- post decrement
	//it should output the value of i first, then decrement
	int i = 100;
	cout << endl << "i = " << i << endl;
	cout << "i-- = " << i-- << endl;	//displays 100
	
	//--i pre decrement
	//it should decrement first, then output
	i = 100;
	cout << endl << "i = " << i << endl;
	cout << "--i = " << --i << endl;	//displays 99
	
	//inline i=i--
	i = 100;
	cout << endl << "i = " << i << endl;
	cout << "INLINE (i = i--) = " << (i = i--) << endl;
	cout << i << endl;
	
	//standalone i=i--
	i = 100;
	cout << endl << "i = " << i << endl;
	i = i--;
	cout << "STANDALONE (i = i--) = " << i << endl;
	cout << i << endl;
	
	return 0;
}