// Adding sorting and searching to our static array class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<exception>
#include<algorithm>
#include <vector>
using std::cout; 

template<int N> 
class StaticIntegerArray
{
private: 
/*	static const int N = 6;*/ 
	int m_nums[N];

public: 
	void insert(int index, int valueToInsert)
	{
		//if (index > N)
		//{
		//	//std::out_of_range
		//	throw std::out_of_range{ "Index was too large!" };
		//	//assert (requires <cassert>) is another option (apart from "exceptions")

		//}

		m_nums[index] = valueToInsert; 
	}

	int size()
	{
		return N; 
	}

	void print()
	{
		for (int i = 0; i < N; ++i)
		{
			cout << m_nums[i] << " ";
		}
		cout << "\n";
	}

	void mySwap(int firstIndex, int secondIndex)
	{
		int temp = m_nums[firstIndex]; 

		m_nums[firstIndex] = m_nums[secondIndex]; 
		
		m_nums[secondIndex] = temp;

	}

	bool isInAscendingOrder()
	{
		for (int i = 0; i < N - 1; ++i)
		{
			if (m_nums[i] > m_nums[i + 1]) //{1, 2, 3, 4}
			{
				return false; 
			}
		}
		return true; 
	}

	//implement on your own, if interested 
	//void out_of_place_ascending_sort()
	//{
	//	int newArray[N]; 

	//	int currentMin = findMin(m_nums);

	//	newArray[0] = currentMin; 

	//	m_nums.erase(currentMin); 


	//	currentMin = findMin(m_nums)
	//}

	void in_place_ascending_sort()
	{
		//we'll talk about O notation and algorithm analysis (N^2) -> the number of operations (comparisons and swaps)
		for (int leftIndex = 0; leftIndex < N - 1; ++leftIndex)
		{
			for (int rightIndex = leftIndex + 1; rightIndex < N; ++rightIndex)
			{
				if (m_nums[rightIndex] < m_nums[leftIndex])
				{
					//cout << "Swap happened\n";
					//print(); //not nums.print()
					//std::cin.get(); //this can be used to see every update after a swap operation
					//std::swap
					
					//swap(nums[redArrow], nums[greenArrow]); //careful!
					
					mySwap(rightIndex, leftIndex);
					//std::swap(nums[redArrow], nums[greenArrow]); //an alternative swap function in C++ std. lib.
				}
			}
		}
	}


	void myShuffle()
	{
		for (int i = 0; i < N - 1; ++i)
		{
			mySwap(i, rand() % N); 
		}
	}
	
	int mySequentialSearch(int valueToSearchFor)
	{
		for (int i = 0; i < N; ++i)
		{
			if (m_nums[i] == valueToSearchFor)
			{
				return i;
			}
		}
		cout << "The value " << valueToSearchFor << " was not found :(\n";
		return -1; 
		//return //ex: suppose array = {1} and searchValue = 10; 
	}

	/*this algorithm DOES ASSUME that the list is SORTED (in ascending order)*/
	int myBinarySearch(int valueToSearchFor)
	{

		int lowIndex = 0; 
		int highIndex = N - 1; 

		int currentSearchIndex = (highIndex - lowIndex ) / 2; //be wary of array parity (eveness or oddness

		bool found = false; 
		while (!found)
		{
			currentSearchIndex = lowIndex + (highIndex - lowIndex) / 2; 

			if (m_nums[currentSearchIndex] == valueToSearchFor)
			{
				//{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
				found = true; 

			}
			else if (m_nums[currentSearchIndex]  > valueToSearchFor)
			{
				cout << "Middle index value was too high!\n";
				highIndex = currentSearchIndex -1; 

			}

			else //m_nums[mid> < valueToSearchFor
			{
				cout << "MIddle index value was too LOW\n";
				lowIndex = currentSearchIndex + 1; 
			}
			//2^20 
		}

		if (found)
		{
			return currentSearchIndex; 
		}

		
	}
}; //end StaticIntegerArray class def. 

void printNums(const std::vector<int>& nums)
{
	for (auto& element : nums)
	{
		cout << element << " ";
	}
	cout << "\n";
}

int main()
{

	const int N = 10; //this is getting at "Big O notation" 
	StaticIntegerArray<N> nums; 

	srand(time(0));

	for (int i = 0; i < N; ++i)
	{
		nums.insert(i, pow(2, i)); //an homage to the fact that binary search complexity O(log2(N))
	}
	//nums.in_place_ascending_sort(); 

	nums.print(); //{1, 2, 3, 4, 5, 6, 7, 8, 9}
	//recall! I tried to use nums.print() in the member function above!
	//(a decent argument for use of "Hungarian notation")
	
	//now let's write some SEARCH algorithms (linear and binary)

	while (true)
	{
		cout << "Enter a number - we'll check if it is in the array:\n";
		int numberToSearchFor  = 64;
		//std::cin >> numberToSearchFor; //5 
		//{ 5, 5, 5 5, 5 };

		//cout << "That number was? found at index: " << nums.mySequentialSearch(numberToSearchFor) << "\n";


		cout << "That number " << numberToSearchFor << "was (was not?) found at index : " 
			<< nums.myBinarySearch(numberToSearchFor) << "\n";

	}


	//std::vector<int> dynamicNums = { 11, 22, 33, 44 }; 

	//cout << "Permutations of dynamic nums: \n";
	//while (std::next_permutation(dynamicNums.begin(), dynamicNums.end()))
	//{
	//	printNums(dynamicNums); 
	//}




	//nums.insert(0, 6); 
	//nums.insert(1, 5);
	//nums.insert(2, 1);
	//nums.insert(3, 3);
	//nums.insert(4, 2);
	//nums.insert(5, 4);

	//cout << "Initial contents of nums array: \n";
	//nums.print(); 

	////swap values 1 and 4 (indices 2 and 5): 
	//int firstIndex = 2; 
	//int secondIndex = 5; 
	//nums.mySwap(firstIndex, secondIndex);

	////cout << "After swapping positions " << firstIndex << " and " << secondIndex << "\n";
	//nums.print(); //6, 5, 4, 3, 2, 1? 

	////put the array in ascending order: 
	//nums.in_place_ascending_sort(); 
	//cout << "\n\nAfter calling the ascending sort function: \n";
	//nums.print(); //this should print 1, 2, 3, 4,5 , 6

	//srand(time(0)); 

	//
	//nums.myShuffle();
	//cout << "\n\n\nAfter shuffling - is the list re-randomized?\n";
	//nums.print(); 



}
