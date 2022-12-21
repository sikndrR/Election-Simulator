#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <time.h>
#include "Election.h"

using namespace std;

bool isPositiveNum(string& str) {
	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}
bool isFloat(string& myString) {
	std::istringstream temp(myString);
	float f;
	temp >> noskipws >> f; // noskipws considers leading whitespace invalid
	// Check the entire string was consumed and if either failbit or badbit is set
	return temp.eof() && !temp.fail();
}


int main() {
	cout << "--------------------------------------ELECTION SIMULATION--------------------------------------\n\n";
	cout << "Please enter the number of candidates: ";
	string num;
	getline(cin, num);
	while (!isPositiveNum(num) || stoi(num) <= 0) {
		cout << "Please enter a positive number: ";
		getline(cin, num);
	}
	int n = stoi(num);
	cout << "Please enter details of each candidate below: \n\n";
	
	srand(static_cast <unsigned> (time(0)));

	vector<Candidate> candidates;
	float sumProb = 0;
	for (int i = 0; i < n; i++) {
		cout << "Enter Name of Candidate # " << i + 1 << " : ";
		string name;
		getline(cin,name);
		
		while (true) {
			bool isFound = 0;
			for (int j = 0; j < candidates.size(); j++) {
				if (candidates[j].firstName == name) {
					isFound = 1;
					break;
				}
			}
			if (isFound) {
				cout << "The candidate name already exists, please enter another name : ";
				getline(cin, name);
				isFound = 0;
			}
			else {
				break;
			}
		}

		Candidate temp(name);
		
		cout << "Enter Winning Probability of Candidate # " << i + 1 << " : ";
		string prob;
		getline(cin, prob);
		while (!isFloat(prob) || stof(prob) < 0 || stof(prob) > 1) {
			cout << "Please enter a positive probability between 0.0 and 1.0 : ";
			getline(cin, prob);
		}
		float vp = stof(prob);
		temp.setProbability(vp);
		sumProb += temp.getProbability();
		
		while (sumProb > 1) {
			sumProb -= vp;
			cout << "The overall sum of probabilities has become greater than one! Please re-enter a probability of last candidate less than or equal to " << 1 - sumProb << " : ";	
			getline(cin, prob);
			while (!isFloat(prob) || stof(prob) < 0 || stof(prob) > 1) {
				cout << "Please enter a positive probability between 0.0 and 1.0 : ";
				getline(cin, prob);
			}
			vp = stof(prob);
			temp.setProbability(vp);
			sumProb += vp;
		}
		if (i == n - 1 && sumProb != 1) {
			sumProb -= vp;
			vp = 1 - sumProb;
			cout << "The overall sum of probabilitiesis not one! Changing probability of last input to " << vp << endl;
			temp.setProbability(vp);
			sumProb += vp;
		}
		candidates.push_back(temp);
	}
	cout << "Enter the number of total votes : ";
	string vote;
	getline(cin, vote);
	while (!isPositiveNum(vote) || stoi(vote) <= 0) {
		cout << "Please enter a positive number: ";
		getline(cin, vote);
	}
	int votes = stoi(vote);
	cout << "\nRunning the election Now.....\n And the winner(s) Are!\n\n";
	ElectionSimulation election(candidates, n);
	vector<Candidate> winners = election.findWinner(votes);
	for (int i = 0; i < winners.size(); i++) {
		winners[i].print();
	}
	while (winners.size() > 1) {
		cout << "There were more than one winners because noone got more than 50% vote, so running runoff re-election... And the new winner(s) Are!\n\n";

		//before reelection, reassign the winning probabilities as number of candidates has increased.
		//We do this by dividing the remaining probability (out of 1) among the candidates.

		float sumProb = 0;
		for (int i = 0; i < winners.size(); i++) {
			sumProb += winners[i].getProbability();
			winners[i].votes = 0; //reset votes
		}
		sumProb = (1 - sumProb) / winners.size(); //calculate amount of probability to add to each candidate

		//increase probability of each candidate
		for (int i = 0; i < winners.size(); i++) {
			winners[i].setProbability(winners[i].getProbability() + sumProb);
		}

		winners = election.findWinner(winners, winners.size(), votes * 0.80);  //have an election with 80% of the votes among the previous winners

		for (int i = 0; i < winners.size(); i++) {
			winners[i].print();
		}
	}

	cout << "\n\nThank you ! GoodBye! \n\n";

	return 0;

}