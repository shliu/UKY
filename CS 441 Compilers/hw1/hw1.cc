#include <iostream>
using namespace std;

struct Huge
{
	int *myVector;
	int myVectorSize;
	
	//constructor
	Huge() : myVector(new int[1]), myVectorSize(0){}
	//copy constructor
	Huge(const Huge& other) : myVector(new int[1]), myVectorSize(0)
	{
		for(int i = 0; i<other.myVectorSize; i++)
		{
			myVector[i] = other.myVector[i];
			myVectorSize++;
		}
	}
	//copy assignment operator
	Huge& operator=(const Huge& other)
	{
		for(int i = 0; i<other.myVectorSize; i++)
		{
			myVector[i] = other.myVector[i];
			myVectorSize++;
		}
	}
	//destructor
	~Huge()
	{
		cout << "freed memory at " << myVector << endl;
		delete[] myVector;
	}
};


int main()
{
	Huge v1;		//uses constructor
	Huge v2 = v1;	//requires custom copy assignment operator
	Huge v3(v1);	//requires custom copy constructor
	
	return 0;
}