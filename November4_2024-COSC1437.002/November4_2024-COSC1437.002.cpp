// November4_2024-COSC1437.002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout; 
using std::string; 

class Planet
{
public:
	string name; 
	double mass; 


	Planet()
	{

	}

	Planet(string name, double mass)
		:name(name), mass(mass)
	{

	}
	//int a = 1; 
	//a++; 
	//?:
	Planet operator + (const Planet& otherPlanet)
	{
		Planet resultingPlanet; 
		resultingPlanet.mass = this->mass + otherPlanet.mass; 

		return resultingPlanet; 

	}
};

class Person
{
	string name; 
	int age; 


	bool operator == (const Person& otherPerson)
	{
		//if (this->age == otherPerson.age
		//	&&
		//	this->name == otherPerson.name)
		//{
		//	return true; 
		//}

		//else
		//{
		//	return false; 
		//}

		return (this->age == otherPerson.age
			&&
			this->name == otherPerson.name);
	}
};

int main()
{
	Planet ourPlanet{ "Earth", 6 * pow(10, 24)};

	Planet otherPlanet{ "Saturn", 6 * pow(10, 26) };

	Planet superPlanet = ourPlanet + otherPlanet; //this is one example of an "overloaded operator" 

	cout << superPlanet.mass << "\n";

	
	//if (ourPlanet == otherPlanet)
	//{
	//	cout << "same planet\n";
	//}

	//else
	//{
	//	cout << "DIFFERENT planet...\n";
	//}


}
