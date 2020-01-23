
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Pathfinder.h"


int main() {

	std::ifstream ifs; // create the stream to read in from the files
	std::ofstream ofs; // create the output stream to write to an output file
	std::string temp; // used to store the current instruction
	Pathfinder* pathptr = NULL;//the Pathfinder
	
	// Test 2D array
	pathptr = new Pathfinder();
	pathptr->importMaze("2D.txt");
	cout << pathptr->toString();
	pathptr->solveMaze();
	exit(0);
	// End of Test 2D array


}

