//CSCI40300 Project Two
//Group Swan:
//Tyler Phillips, Kevin Kolcheck, Benjamin Fulkerson-Bird, Daniel Adams

#include "random.hpp"
#include "time.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 3){ // check for two command-line arguments
		cout << "Usage: " << argv[0] << " iterations mean" << endl;
		return 1;
	}

	int iterations;
	stringstream s1(argv[1]);
	s1 >> iterations;
	if (s1.fail()) { // check that iterations argument is an int
		cout << "iteration parameter is invalid, please enter an integer" << endl;
		cout << "Usage: " << argv[0] << " iterations mean" << endl;
		return 1;
	}

	double mean;
	stringstream s2(argv[2]);
	s2 >> mean;
	if (s2.fail()) { // check that mean argument is a double
		cout << "mean parameter is invalid, please enter a double" << endl;
		cout << "Usage: " << argv[0] << " iterations mean" << endl;
		return 1;
	}

	cout << "psleep program!" << endl;
	cout << "iterations: " << iterations << endl;
	cout << "mean: " << mean << endl << endl;
	cout << iterations << " iterations in approx. mean interval " << mean << " seconds" << endl;

	int seed = 0;   // we will use srand(time(NULL)) to seed our pseudo random number generator
	random_seed(seed);

	printDateTime();

	double random = 0.0;
	for(int i = 0; i < iterations; i++){
		random = random_exponential(mean);
	}

	return 0;
}
