// Adding sorting and searching to our static array class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<exception>
#include<algorithm>
using std::cout; 

//template<int capacity> 
class StaticIntegerArrayOfSIXNums
{
private: 
	static const int N = 6; 
	int nums[N];

public: 
	void insert(int index, int valueToInsert)
	{
		if (index > N)
		{
			//std::out_of_range
			throw std::out_of_range{ "Index was too large!" };
			//assert (requires <cassert>) is another option (apart from "exceptions")

		}

		nums[index] = valueToInsert; 
	}

	int size()
	{
		return N; 
	}

	void print()
	{
		for (int i = 0; i < N; ++i)
		{
			cout << nums[i] << " ";
		}
		cout << "\n";
	}

	void mySwap(int firstIndex, int secondIndex)
	{
		int temp = nums[firstIndex]; 

		nums[firstIndex] = nums[secondIndex]; 
		
		nums[secondIndex] = temp;


	}

	bool isInAscendingOrder()
	{
		for (int i = 0; i < N - 1; ++i)
		{
			if (nums[i] > nums[i + 1]) //{1, 2, 3, 4}
			{
				return false; 
			}
		}
		return true; 
	}

	void in_place_ascending_sort()
	{
		for (int greenArrow = 0; greenArrow < N - 1; ++greenArrow)
		{
			for (int redArrow = greenArrow + 1; redArrow < N; ++redArrow)
			{
				if (nums[redArrow] < nums[greenArrow])
				{
					//cout << "Swap happened\n";
					//print(); 
					//std::cin.get(); //this can be used to see every update after a swap operation
					
					//swap(nums[redArrow], nums[greenArrow]); //careful!
					mySwap(redArrow, greenArrow);
					//std::swap(nums[redArrow], nums[greenArrow]); //an alternative swap function in C++ std. lib.
				}
			}
		}
	}
};

int main()
{

	StaticIntegerArrayOfSIXNums nums; 
	nums.insert(0, 6); 
	nums.insert(1, 5);
	nums.insert(2, 1);
	nums.insert(3, 3);
	nums.insert(4, 2);
	nums.insert(5, 4);

	cout << "Initial contents of nums array: \n";
	nums.print(); 

	//swap values 1 and 4 (indices 2 and 5): 
	int firstIndex = 2; 
	int secondIndex = 5; 
	nums.mySwap(firstIndex, secondIndex);

	//cout << "After swapping positions " << firstIndex << " and " << secondIndex << "\n";
	nums.print(); 

	//put the array in ascending order: 
	nums.in_place_ascending_sort(); 
	cout << "\n\nAfter calling the ascending sort function: \n";
	nums.print(); 

}
