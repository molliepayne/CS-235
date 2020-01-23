#pragma once
#include "PathfinderInterface.h"


class Pathfinder: public PathfinderInterface{

protected:
		const static int ROW_SIZE = 5;
		const static int COL_SIZE = 5;
		const int BACKGROUND = 1;
		const int WALL = 0;
		const int TEMPORARY = 2; // Used to show this path has been explored
		const int PATH = 3;
		int maze_grid[ROW_SIZE][COL_SIZE]; // To hold values
		vector<string> solution;
public: 
	Pathfinder() {};
	~Pathfinder() {};
	
	
	string toString() const;


	void createRandomMaze();

	bool importMaze(string file_name);
	
	vector<string> solveMaze();
    bool find_maze_path(int grid[ROW_SIZE][COL_SIZE], int r, int c);
};


