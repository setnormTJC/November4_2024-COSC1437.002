// Dec 2 - playing with a few standard library algorithsm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<algorithm> 


#include<vector> 

using std::cout; 
using std::vector; 

template<typename T> 
void printVec(vector<T> listOfThings)
{
    for (const auto& element : listOfThings)
    {
        cout << element << " ";
    }

    cout << "\n";
}

int main()
{
    //std::cout << "Hello World!\n";
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 11, 11, 33, 11, 22, 33, 44, 77 };


    //auto number = 3; 
    std::vector<int>::iterator result = std::adjacent_find(nums.begin(), nums.end());

    if (result != nums.end())
    {
        cout << *result << "\n";

    }
    
    auto resultOfSTDAll = std::all_of(nums.begin(), nums.end(),
        []
        (int num)
        {
            return num > -2;
        }
    ); 

    cout << std::boolalpha; 
    cout << "Look here: " << resultOfSTDAll << "\n";


    cout << "\n\n\n";
    cout << "After calling the fill function, the vector contents are: \n";
    std::fill(nums.begin() + 4, nums.end(), 42);

    printVec(nums); 

    //begin brute force password hack!
    vector<char> someLetters = { 'm', 'u', 'e', 'x', 'g', 'f', 'r'};

    cout << "The results of calling `next_permutation` on an array of letters:\n";

    //while (std::next_permutation(someLetters.begin(), someLetters.end()))
    //{
    //    printVec(someLetters); 

    //}


    cout << "\n\n\nResults of merging a list of even numbers and odd numbers up to 20\n";
    vector<int> evens = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    vector<int> odds = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    std::inplace_merge(evens.begin(), evens.begin() + 6, odds.end());
    cout << "Evens has become: \n";
    printVec(evens); 

    cout << "Odds has become:\n";
    printVec(odds); 
   

}
