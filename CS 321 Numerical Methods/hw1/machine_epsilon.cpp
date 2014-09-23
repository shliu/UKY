#include <iostream>
using namespace std;

int main()
{
	float ep = 1.0f;
	int i = 0;

	do {
		ep = ep / 2;
		i++;
	}while(1 + ep != 1);

	cout << "The machine epsilon was: " << ep << endl
		<< "It took " << i << " iterations" << endl;

	return 0;
}
