#include "Election.h"


	//default constructor
ElectionSimulation::ElectionSimulation() {
		numberOfCandidates = 0;
	}
	//parametrized constructor
ElectionSimulation::ElectionSimulation(vector<Candidate> lc, int nc) {
		listOfCandidates = lc;
		numberOfCandidates = nc;
	}


	//find winner(s) given a number of votes and return using a vector
	vector<Candidate> ElectionSimulation::findWinner(int numOfVotes) {
		vector<Candidate> winners;

		//determine the votes of each candidate by generating a random number between 0 and 1. if random number lies in a specific range, then then the vote goes to the candidate assigned to that range
		//the higher the probability of wining of a cnadidate, the higher the range in which he gets a vote


		for (int i = 0; i < numOfVotes; i++) {
			float number = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			//the range is found as (start where the last range ended , and end at start+probability)
			float rangeStart = 0;
			float rangeEnd = 0;
			for (int j = 0; j < numberOfCandidates; j++) {
				rangeStart = rangeEnd;
				rangeEnd += listOfCandidates[j].getProbability();
				if (number >= rangeStart && number <= rangeEnd) {
					//If random number i.e random vote was inside a candidates range, then increase the candidate's votes

					listOfCandidates[j].votes++;
					break;
				}
			}

		}
		float maxVotes = 0;  //maximum votes
		float maxVotes2 = 0; //second maximum votes
		for (int i = 0; i < numberOfCandidates; i++) {
			if (maxVotes < listOfCandidates[i].votes) {
				maxVotes2 = maxVotes;
				maxVotes = listOfCandidates[i].votes;
			}
		}
		//if the winner had more than 50% of the votes then return only that candidate
		if (maxVotes > numOfVotes * 0.5) {
			for (int i = 0; i < numberOfCandidates; i++) {
				if (listOfCandidates[i].votes == maxVotes) {
					winners.push_back(listOfCandidates[i]);
					return winners;
				}
			}
		}
		//otherwise return top two candidates
		else {
			//Firstly insert candidate(s) with maximum votes
			for (int i = 0; i < numberOfCandidates; i++) {
				if (listOfCandidates[i].votes == maxVotes) {
					winners.push_back(listOfCandidates[i]);
				}
			}
			//If there was only one such candidate, then also insert candidate(s) with second maximum
			if (winners.size() == 1) {
				for (int i = 0; i < numberOfCandidates; i++) {
					if (listOfCandidates[i].votes == maxVotes2) {
						winners.push_back(listOfCandidates[i]);
					}
				}
			}
		}
		return winners;
	}

	//find winner of runoff election, 80% of prev votes will be passed here alongwith prev winners
	vector<Candidate> ElectionSimulation::findWinner(vector<Candidate> prevWinners, int num, int numOfVotes) {
		vector<Candidate> winners;

		//determine the votes of each candidate by generating a random number between 0 and 1. if random number lies in a specific range, then then the vote goes to the candidate assigned to that range
		//the higher the probability of wining of a cnadidate, the higher the range in which he gets a vote
		for (int i = 0; i < numOfVotes; i++) {
			float number = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

			float rangeStart = 0;
			float rangeEnd = 0;
			for (int j = 0; j < num; j++) {
				rangeStart = rangeEnd;
				rangeEnd += prevWinners[j].getProbability();
				if (number >= rangeStart && number <= rangeEnd) {
					prevWinners[j].votes++;
					break;
				}
			}

		}

		float maxVotes = 0;  //maximum votes
		float maxVotes2 = 0; //second maximum votes
		for (int i = 0; i < num; i++) {
			if (maxVotes < prevWinners[i].votes) {
				maxVotes2 = maxVotes;
				maxVotes = prevWinners[i].votes;
			}
		}
		//if the winner had more than 50% of the votes then return only that candidate
		if (maxVotes > numOfVotes * 0.5) {
			for (int i = 0; i < num; i++) {
				if (prevWinners[i].votes == maxVotes) {
					winners.push_back(prevWinners[i]);
					return winners;
				}
			}
		}
		//otherwise return top two candidates
		else {
			//Firstly insert candidate(s) with maximum votes
			for (int i = 0; i < num; i++) {
				if (prevWinners[i].votes == maxVotes) {
					winners.push_back(prevWinners[i]);
				}
			}
			//If there was only one such candidate, then also insert candidate(s) with second maximum
			if (winners.size() == 1) {
				for (int i = 0; i < num; i++) {
					if (prevWinners[i].votes == maxVotes2) {
						winners.push_back(prevWinners[i]);
					}
				}
			}
		}
		return winners;
	}


	ElectionSimulation::~ElectionSimulation() {
		numberOfCandidates = 0;
		//vector is automatically deleted
	}
