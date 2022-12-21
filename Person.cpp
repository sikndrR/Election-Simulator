#include "Person.h"
#include <iostream>

	//default constructor
	Person::Person() {
		firstName = "";
		lastName = "";
		age = 0;
	}
	//parametrized constructor
	Person::Person(string fname, string lname , int a) {
		firstName = fname;
		lastName = lname;
		age = a;
	}
	//copy constructor
	Person::Person(const Person& p) {
		firstName = p.firstName;
		lastName = p.lastName;
		age = p.age;
	}

	//print function
	void Person::print() {
		cout << firstName << " " << lastName;

	}
	//overload assignment operator
	Person Person::operator=(const Person& p) {
		firstName = p.firstName;
		lastName = p.lastName;
		age = p.age;
		return *this;
	}
	//overload == operator
	bool Person::operator==(const Person& p) {
		if (firstName == p.firstName && lastName == p.lastName && age == p.age)
			return true;
		return false;
	}
	//destructor
	Person::~Person() {
		firstName = "";
		lastName = "";
		age = 0;
	}
