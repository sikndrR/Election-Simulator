#pragma once
#include <string>

using namespace std;

class Person {
	string lastName;
	int age;
public:
	// Public for ease of use
	string firstName;
	//default constructor
	Person();
	//parametrized constructor
	Person(string fname, string lname = "", int a = 30);
	//copy constructor
	Person(const Person& p);

	//print function
	void print();
	//overload assignment operator
	Person operator=(const Person& p);
	//overload == operator
	bool operator==(const Person& p);
	//destructor
	~Person();
};