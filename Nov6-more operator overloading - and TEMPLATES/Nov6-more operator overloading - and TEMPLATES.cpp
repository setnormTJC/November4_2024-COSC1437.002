// Nov6-more operator overloading - and TEMPLATES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>



using std::cout; 
using std::string; 




//templates allow "generic programming" 
// example of a template function:
template<typename T1, typename T2> //
auto printSomeDataTypeT(T1 thing1, T2 thing2)
{
	cout << "Thing1 is: " << thing1 << "\n";
	cout << "Thing2 is: " << thing2 << "\n";
}

//an example of a template class (child class below has array of elements of type T): 
template<typename T> 
class AbstractArrayType
{

public: 
	virtual void insert(int indexAtWhichToInsert, T itemToInsert) = 0; 
	//again, virtual means "can be overridden" (by children classes) 

};

template<typename T>
class CustomStaticArray : public AbstractArrayType<T>
{
private:
	static const int MAX_NUMBER_ELEMENTS = 5; 
	T data[MAX_NUMBER_ELEMENTS]; //C-style static array (a POINTER in disguise)

public: 
	CustomStaticArray()
	{
		for (int i = 0; i < MAX_NUMBER_ELEMENTS; ++i)
		{
			data[i] = T{};
		}
	}
	void insert(int indexAtWhichToInsert, T itemToInsert)
	{

	}

	//next time... an overloaded subscript operator 
	//T operator [] (int index)
	//{
	//	
	//}
};

int main()
{
	//int a{}; //new C++ style of initiliazing
	//cout << a << "\n";

	//printSomeDataTypeT(1, "alpha");
	//
	//cout << "\n\n";
	//cout << std::boolalpha; 

	//printSomeDataTypeT('z', true);

	//std::vector<int> nums; //angle brackets (template parameter) 
	//std::vector<string> words; 
	

}
