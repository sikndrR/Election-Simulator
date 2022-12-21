#include "Candidate.h"
#include <iostream>



	//default constructor
	Candidate::Candidate() : Person() {
		votes = 0;
		voteProbability = 0;
	}
	//parametrized constructor
	Candidate::Candidate(string fname, string lname , int age , float vp) : Person(fname, lname, age) {
		votes = 0;
		voteProbability = vp;
	}
	//copy constructor
	Candidate::Candidate(const Candidate& c) : Person(c) {
		voteProbability = c.voteProbability;
		votes = c.votes;
	}
	void Candidate::setProbability(float vp) {
		voteProbability = vp;
	}
	float Candidate::getProbability() {
		return voteProbability;
	}
	//print function
	void Candidate::print() {
		Person::print();
		cout << " Winning Probability : " << voteProbability << " Number of votes achieved : " << votes << endl;
	}
	//overload assignment operator
	Candidate Candidate::operator=(const Candidate& c) {
		Person::operator=(c);
		voteProbability = c.voteProbability;
		return c;
	}
	//overload == operator
	bool Candidate::operator==(const Candidate& c) {

		if (Person::operator==(c) && voteProbability == c.voteProbability)
			return true;
		return false;
	}

	//destructor
	Candidate::~Candidate() {
		voteProbability = 0;
	}
