// 10307_Killing_Aliens_in_Borg_Maze_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>

void bfs();
void mst();

void bfs() 
{

}

void mst() 
{

}

int main()
{
	
	int testCases;
	std::cin >> testCases;
	for (auto i = 0; i < testCases; i++)
	{
		int numOfRows, numOfCols, numOfNodes, startIndexRow, startIndexColumn;

		std::string line;
		std::vector<std::string> maze;
		std::vector<std::pair<int, int>> aliens;

		std::cin >> numOfCols >> numOfRows;
		std::getline(std::cin, line); //first row is only walls

		for (auto j	 = 0; i < numOfRows; i++)
		{
			std::getline(std::cin, line);
			maze.push_back(line);
		}

		for (auto r = 0; r < numOfRows; r++)
		{
			for (auto c = 0; c < numOfCols; c++)
			{
				if (maze[r][c] == 'A')
				{
					aliens.push_back(std::pair<int, int>(r, c));
				}
				else if (maze[r][c] == 'S')
				{
					startIndexRow = r;
					startIndexColumn = c;
				}
			}
		}

		numOfNodes = numOfRows * numOfCols;
		std::vector < std::set<int>> adjList(numOfNodes);
		for (auto sr = 0; sr < numOfRows; sr++)
		{
			for (auto sc = 0; sc < numOfCols; sc++)
			{
				std::vector<std::pair<int, int>> neighbours;
				neighbours.push_back(std::pair<int, int>(sr - 1, sc));
				neighbours.push_back(std::pair<int, int>(sr + 1, sc));
				neighbours.push_back(std::pair<int, int>(sr, sc - 1));
				neighbours.push_back(std::pair<int, int>(sr, sc + 1));


			}
		}

	}
    return 0;
}

