#pragma once
#include "Candidate.h"
#include <vector>

class ElectionSimulation {

	//This list has actual candidate objects, thus there is composition in place here
	vector<Candidate> listOfCandidates;
	int numberOfCandidates;

public:

	//default constructor
	ElectionSimulation();
	//parametrized constructor
	ElectionSimulation(vector<Candidate> lc, int nc);


	//find winner(s) given a number of votes and return using a vector
	vector<Candidate> findWinner(int numOfVotes);

	//find winner of runoff election, 80% of prev votes will be passed here alongwith prev winners
	vector<Candidate> findWinner(vector<Candidate> prevWinners, int num, int numOfVotes);
	
	~ElectionSimulation();
};
