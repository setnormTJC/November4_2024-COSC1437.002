// Nov6-more operator overloading - and TEMPLATES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<set>
#include<initializer_list>
#include<fstream> 
#include<cassert> //for assert ...


using std::cout;
using std::string;
using std::ostream; 



//templates allow "generic programming" 
// example of a template function:
template<typename T1, typename T2> //
auto printSomeDataTypeT(T1 thing1, T2 thing2)
{
	cout << "Thing1 is: " << thing1 << "\n";
	cout << "Thing2 is: " << thing2 << "\n";
}

//templates allow "generic programming" 
// example of a template function:
//template<typename T1, typename T2> //
//auto printSomeDataTypeT(T1 thing1, T2 thing2)
//{
//	cout << "Thing1 is: " << thing1 << "\n";
//	cout << "Thing2 is: " << thing2 << "\n";
//}


//an example of a template class (child class below has array of elements of type T): 
template<typename T>
class AbstractArrayType
{

public:
	virtual void insert(int indexAtWhichToInsert, T itemToInsert) = 0;
	//again, virtual means "can be overridden" (by children classes) 

};

template<typename T, int MAX_NUMBER_ELEMENTS>
class CustomStaticArray : public AbstractArrayType<T>
{
private:
	//static const int MAX_NUMBER_ELEMENTS = 5;
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
		//should we prevent running out of bounds? 
		assert(indexAtWhichToInsert < MAX_NUMBER_ELEMENTS);

		listOfThings[indexAtWhichToInsert] = itemToInsert; 
	}

	void print()
	{
		for (int i = 0; i < MAX_NUMBER_ELEMENTS; ++i)
		{
			cout << listOfThings[i] << "\n";
		}
	}
	//at (index)
	//next time... an overloaded subscript operator 
	T& operator [] (int index)
	{
		return listOfThings[index]; 
	}

	//More "typical" addition definition - perhaps - adds given value to every element in array 
	void operator + (T thingToAdd)
	{
		for (int i = 0; i < MAX_NUMBER_ELEMENTS; ++i)
		{
			listOfThings[i] += thingToAdd;
		}
	}

	/*CONCATENATION - Restricted in assuming that the two operands (arrays) have the same number of elements*/
	CustomStaticArray<T, MAX_NUMBER_ELEMENTS * 2> operator + (CustomStaticArray<T, MAX_NUMBER_ELEMENTS>& otherArray)
	{
		CustomStaticArray<T, MAX_NUMBER_ELEMENTS * 2> newArray; 

		for (int i = 0; i < MAX_NUMBER_ELEMENTS; ++i)
		{
			newArray.insert(i, this->listOfThings[i]);
		}

		for (int i = MAX_NUMBER_ELEMENTS; i < MAX_NUMBER_ELEMENTS * 2; ++i)
		{	
			newArray.insert(i, otherArray[i - MAX_NUMBER_ELEMENTS]);
		}

		return newArray; 
	}

};

//added AFTER lecture:
template<typename T>
class VectorWrapperClass : public AbstractArrayType<T>
{
	std::vector<T> data;
	//perhaps our implementation of an array data structure just uses vector and then adds a few "special" functions 

};

class Car
{
	int numberOfMiles;
	double cost;

public:
	Car(int numberOfMiles, double cost)
		:numberOfMiles(numberOfMiles), cost(cost)
	{

	}

	/*The overloaded PRE-increment operator (NOT the POST increment operator)*/
	Car operator ++()
	{
		this->cost++; 
		this->numberOfMiles++; 

		return *this; //this is a pointer, * gets the contents of this memory address
	}

	friend ostream& operator << (ostream& os, const Car& carObject)
	{
		os << carObject.cost << "\t" << carObject.numberOfMiles << "\n";
		return os; 
	}
	//Car()
	//{
	//	cout << "Default constructor called...\n";
	//}
};

int main()
{
	//int a = -3
	//Car carObject{ 1, 99'999 };
	////carObject++; //error - really?
	//++carObject; 

	////let's write the car info to an OUTPUT file (not cout) 
	//cout << carObject << "\n";

	//std::ofstream fout{ "outputFile.txt" };

	//fout << carObject << "\n"; //<< operator works for ostream and ofstream objects! Hooray!
	//int a = 0; 
	//int b{}; 
	//Car c{};
	//cout << a << "\t" << b << "\n";


	//Car myCar{ 200'000, "Ford" }; 
//	string s{};

	//cout << "What is s? " << s << "\n"; 

	CustomStaticArray <string, 5> listOfWords{}; //this will call default constructor 
	listOfWords.insert(0, "alpha");

	//listOfNames.insert(199, "zeta"); 
	listOfWords[1] = "beta"; //this will call the overloaded subscript operator 

	listOfWords.print(); 

	CustomStaticArray <string, 5> 	anotherListOfWords;
	anotherListOfWords[0] = "dog"; 
	anotherListOfWords[1] = "zebra";

	anotherListOfWords.print(); 
	CustomStaticArray<string, 10> joinedListOfWords = listOfWords + anotherListOfWords; 

	cout << "Joined array:\n";
	joinedListOfWords.print(); 

	//demoing the SECOND overload of the addition operator: 
	string thingToAdd = "abcdef";
	joinedListOfWords + thingToAdd;
	//alterantive syntax: 
	//joinedListOfWords.operator+()
	//joinedListOfWords.operator+(thingToAdd);


	cout << "\n\nAfter \"adding\" " << thingToAdd << "\n";

	joinedListOfWords.print(); 

	//std::vector<int> nums; 
	//CustomStaticArray<string> csa; 
	//csa.insert(0, "alpha");
	//csa[0] = "asdfasfdasdf";
	////cout << "Address of data at given index (within MAIN): " << &(csa[0]) << "\n";
	//cout << csa.operator[](0) << "\n";
	
	//int a{}; //new C++ style of initializing
	//cout << a << "\n";


	//Demoing function templates below: 
	//printSomeDataTypeT(1, "alpha");
	//
	//cout << "\n\n";
	//cout << std::boolalpha; 

	//printSomeDataTypeT('z', true);

	//std::vector<int> nums; //angle brackets (template parameter) 
	//std::vector<string> words; 


}
