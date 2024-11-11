// Nov6-more operator overloading - and TEMPLATES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>



using std::cout; 
using std::string; 
using std::ostream; 

struct Car
{

};


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
	T listOfThings[MAX_NUMBER_ELEMENTS]; //C-style static array (a POINTER in disguise)

public: 
	CustomStaticArray()
	{
		for (int i = 0; i < MAX_NUMBER_ELEMENTS; ++i)
		{
			listOfThings[i] = T{};
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

//added AFTER lecture:
template<typename T> 
class VectorWrapperClass : public AbstractArrayType<T>
{
	std::vector<T> data;
	//perhaps our implementation of an array data structure just uses vector and then adds a few "special" functions 

};

//class Person
//{
//private:
//	string phoneNumber = "867-5309";
//	int age;
//
//public:
//	Person()
//	{
//
//	};
//
//
//	//<< is left bitshift 
//	friend ostream& operator << (ostream& os, const Person& p)
//	{
//		os << p.age << "\t" << p.phoneNumber << "\n";
//		return os; 
//	}
//
//	friend void demoFriendCallingPrivateNumber(const Person& somePerson);
//	//this declaration gives this FRIEND function access to the private member variable(phone number) 
//	//friendship can only be given BY a class (inside)
//};

//void demoFriendCallingPrivateNumber(const Person& somePerson)
//{
//	cout << "Hey, bro, I'm calling you at yo numba, which is: " << somePerson.phoneNumber << "\n";
//}

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
	Person p; 
	string word = "pop";
	cout <<word << "\n";
	//p.setNumber("asdfasdf")
	cout << p << "\n"
	//p.phoneNumber; 
	//demoFriendCallingPrivateNumber(p); 

}
