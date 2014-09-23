/*
Steven Liu
CS315
HW2

Finds dominant element in array.  "Dominant" means an element has copies of itself > half the array size.

Change "size" and "array[]" elements to match size then compile and run the program

Should be in time complexity O(nlogn) because:
	T(n) = 2T(n/2)+n
		a=2, b=2, d=1
		log(2)/log(2) = 1
		logba = d
		O(n^d logn)
		= O(n^1 logn)
		= O(nlogn)
*/


#include <iostream>
#include <string>

using namespace std;

int find_dominant(int array[], int start, int end);
int confirm_dominant(int array[], int start, int end, int dom_left, int dom_right);


int main()
{
	const int size	= 7;
	int array[size] = {1, 5, 5, 6, 5, 7, 5};
	
	int dominant	= find_dominant(array, 0, size-1);	
	
	cout << "The dominant element in your array is: " << dominant << endl;
	return 0;
}


//recursive function to find dominant value in array
	//T(n) = 2T(n/2)+n
int find_dominant(int array[], int start, int end)
{
	if(start<end)
	{
		int middle		= (start+end)/2;
		
		int dom_left	= find_dominant(array, start, middle);	//T(n/2)
		int dom_right	= find_dominant(array, middle+1, end);	//T(n/2)
		
		return confirm_dominant(array, start, end, dom_left, dom_right);	//worst case is O(n) due to linear search
	}
	else //base case
	{
		return array[start];	//single element = dominant value of array[1]
	}
}


//verifies if the passed sub-dominant elements are also the dominant element of master array
int confirm_dominant(int array[], int start, int end, int dom_left, int dom_right)
{
	if((dom_left==-1) && (dom_right==-1))	//neither subarray has dominant value
	{
		return -1;			//there's no dom in array
	}
	else if(dom_left==dom_right)	//both subarray has same dominate value
	{
		return dom_left;	//subarray's dom value is also array's dom value
	}
	else	//different dominant values in subarray or only one dominant value found
	{
		//verify which is actually dominant by counting only subdom elements
		int dom_left_ctr	= 0,
			dom_right_ctr	= 0;
	
		//linear search to count subdominant elements
		for(int i=start; i<=end; i++)
		{
			if(array[i]==dom_left)
				dom_left_ctr++;
			else if(array[i]==dom_right)
				dom_right_ctr++;
		}
		
		//now check to see if count of subdom elements exceed half the array size
			//definition of dominant is "> half array size"
		int half_array_size	= (end-start+1)/2;
		if(dom_left_ctr > half_array_size)			//left subarray's dom element also dominates array
		{
			return dom_left;
		}
		else if(dom_right_ctr > half_array_size)	//right subarray's dom element also dominates array
		{
			return dom_right;
		}
		else	//neither subarray's dom element dominates array
		{
			return -1;
		}
	}
	
}