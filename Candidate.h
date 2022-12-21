#pragma once
#include "Person.h"

class Candidate : public Person {
	//Proability of candidate winning/getting votes (0 - 1)
	float voteProbability;

public:
	//public variable to be accessed  during election tos tore number of votes
	int votes;

	//default constructor
	Candidate();
	//parametrized constructor
	Candidate(string fname, string lname = "", int age = 30, float vp = 0);
	//copy constructor
	Candidate(const Candidate& c);
	void setProbability(float vp);
	float getProbability();
	//print function
	void print();
	//overload assignment operator
	Candidate operator=(const Candidate& c);
	//overload == operator
	bool operator==(const Candidate& c);

	//destructor
	~Candidate();

};