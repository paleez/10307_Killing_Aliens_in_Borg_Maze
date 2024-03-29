// 10307_Killing_Aliens_in_Borg_Maze_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <fstream>
#include <queue>
#include <map>


/*

2
6 5
#####
#A#A##
# # A#
#S  ##
#####
7 7
#####
#AAA###
#    A#
# S ###
#     #
#AAA###
#####

*/

/*(1) For each starting point/alien location, do simple bfs to find distance to other aliens.(2) Build mst using Prim's algorithm, starting with the starting point*/

/*Adjacency List, usually in form of C++ STL vector<vii> AdjList, withvii deﬁned as:
typedef pair<int, int> ii;
typedef vector<ii> vii; // our data type shortcuts
In Adjacency List, we have a vector of V vertices and for each vertex v,
we store another vector that contains pairs of (neighboring vertex and it’s edge weight)
that have connection to v.
If the graph is unweighted, simply store weight = 0 or drop this second attribute.
With Adjacency List, we can enumerate the list of neighbors of a vertex v eﬃciently.
If there are k neighbors of v, this enumeration isO(k).
As this is one of the most common operations in most graph algorithms,
it is advisable to stick with Adjacency List as your default choice.
*/

typedef std::pair<int, int> intPair;

typedef std::vector<intPair> vii; //fukkk
//typedef std::vector<std::pair<int, int>> vii;

#define _CRT_SECURE_NO_DEPRECATE

#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it !=(c).end(); it++)

int find(int u);
void bfs(int s, std::vector<std::vector<std::pair<int, int>>> adjList);

void bfs(int s, std::map<std::pair<int, int>, int> borgMaze, std::vector<std::pair<int, int>> adjList);

//void mstKruskals();
void mstPrim();

//std::vector<std::pair<int, int>> adjList;

void bfs(int s, std::map<std::pair<int, int>, int> borgMaze)
{
	std::vector<std::vector<std::pair<int, int>>> adjList(200);
	
	std::queue<int> q; //order the sequence of visitation


	std::map<int, int> dist;
	std::map<std::pair<int, int>, int> borg;

	//record if a vertex has been visited or not and also the distance of each vertex from the source vertex

	//this solves single source shortest path problem

	q.push(s);
	dist[s] = 0;
	
	std::cout << "this is dist S; " << s << std::endl;

	while (!q.empty())
	{
		int u = q.front();
		q.pop(); //queue: layer by layer
		TRvii(adjList[u], v)
		{
			if (!dist.count(v->first))
			{
				dist[v->first] = dist[u] + 1; // if v not visited before + reachable from u
				q.push(v->first);
				std::cout << "bfs "  << std::endl;
			}
		}
	}
	
}

void mstKruskals()
{
	int mst_weight = 0;

	//std::priority_queue<std::pair<int, intPair>> edges; // sort by edge weight

	std::vector<std::pair<int, intPair>> edges;
	sort(edges.begin(), edges.end());

	std::vector<std::pair<int, intPair>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		//int setU = find(u);
		//int setV = find(v);
	}
}

struct DisjointSet
{
	int *parent, *rank;
	int n;

	DisjointSet(int n)
	{
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];

		for (auto i = 0; i <= n; i++)
		{
			rank[i] = 0;
			parent[i] = i; //every element s a parent of itself
		}
	}

	//find the parent of node 'u', path compression
	int find(int u)
	{
		//make the parent of the nodes in the path 
		//from u---->parent[u] point to parent[u]
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}
	//union by rank
	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		//Make tree with smaller height, a subtree of the other tree
		if (rank[x] > rank[y])
			parent[y] = x;
		else
			parent[x] = y;

		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
	}
};

void mstPrim()
{

}

int main()
{
	int numOfTestCases;
	int numOfRows, numOfCols, numOfNodes;
	std::string line;
	std::vector<std::string> maze;
	std::vector<std::pair<int, int>> aliens;
	std::vector<std::pair<int, int>> neighbours;
	std::vector<std::pair<int, int>> graphNodes;
	std::map<std::pair<int, int>, int> borgMaze;
	std::cin >> numOfTestCases;

	for (auto i = 0; i < numOfTestCases; i++)
	{
		std::cin >> numOfCols >> numOfRows;
		std::getline(std::cin, line);
		numOfNodes = numOfRows * numOfCols;
		int numOfEdges = numOfNodes - 1;
		std::vector<std::vector<std::pair<int, int>>> adjList(numOfNodes);

		int index = 0;
		for (auto j = 0; j < numOfRows; j++)
		{

			std::cout << "this is j: " << j << std::endl;
			std::cout << "this is numOfRows: " << numOfRows << std::endl;

			if (i == numOfTestCases - 1 && j == numOfRows - 1)
			{
				std::string dummy;
				dummy.assign('#', numOfCols);
				//std::getline(std::cin, dummy);
				//	dummy += dummy + " ";
				//	//std::cout << "im in!!!";
				//	//std::getline(std::cin, dummy);
				//	//std::cin >> dummy;
				//	//std::cin.ignore();
				//	std::cin >> dummy;

				//	//	std::string s;
				//	//	std::cout << "this is line: " << line << std::endl;
				//		std::getline(std::cin, dummy);
				//	//	std::string dummy = "\n";
				//	//	std::string newLine = line + dummy;
				//	//	std::getline(std::cin, newLine);
				//	//	line += "";
				//	//	std::string newLine = "\n";
				//	//	s += newLine;
				//	//	std::getline(std::cin, s);
				//	//	std::getline(std::cin, line);
				//int b = numOfRows * numOfCols;
				//maze.reserve(b);
				maze.push_back(dummy);
				//	//	endOfFile = true;

				break;
			}

			std::getline(std::cin, line);
			std::cout << "testcase : " << i << std::endl;
			std::cout << "this is line :" << line << std::endl;
			std::cout << "this is numOfRows index: " << j << std::endl;


			maze.push_back(line);
		}
		for (auto r = 0; r < numOfRows; r++)
		{
			for (auto c = 0; c < numOfCols; c++)
			{
				if (maze[r][c] == 'A' || maze[r][c] == 'S')
				{
					aliens.push_back(std::make_pair(r, c));
					graphNodes.push_back(std::make_pair(r, c));
					//adjList[index].push_back(graphNodes[r,c]);
					borgMaze[std::make_pair(r, c)] = index++;
					std::cout << "ALIEN   or START   " << " column: " << c << "  row: " << r << std::endl;
					if ((c >= 1 && c < numOfCols - 1) && (r >= 1 && r < numOfRows - 1))
					{

						if (maze[r + 1][c] != '#') //check under
						{
							graphNodes.push_back(std::make_pair(r + 1, c));
							borgMaze[std::make_pair(r + 1, c)] = index++;

						}
						if (maze[r - 1][c] != '#') //check over
						{
							graphNodes.push_back(std::make_pair(r - 1, c));
							borgMaze[std::make_pair(r + 1, c)] = index++;
						}
						if (maze[r][c + 1] != '#') //check to ur right
						{
							graphNodes.push_back(std::make_pair(r, c + 1));
							borgMaze[std::make_pair(r, c + 1)] = index++;
						}
						if (maze[r][c - 1] != '#') //check to ur left
						{
							graphNodes.push_back(std::make_pair(r, c - 1));
							borgMaze[std::make_pair(r, c - 1)] = index++;
						}
					}
				}
				if (maze[r][c] == ' ')
				{
					graphNodes.push_back(std::make_pair(r, c));
					adjList[index].push_back(std::make_pair(r, c));
					borgMaze[std::make_pair(r, c)] = index++;
					std::cout << "SPACE    " << " column: " << c << "  row: " << r << std::endl;
					if ((c >= 1 && c < numOfCols - 1) && (r >= 1 && r < numOfRows - 1))
					{
						if (maze[r + 1][c] != '#') //check under
						{
							graphNodes.push_back(std::make_pair(r + 1, c));
							borgMaze[std::make_pair(r + 1, c)] = index++;
						}
						if (maze[r - 1][c] != '#') //check over
						{
							graphNodes.push_back(std::make_pair(r - 1, c));
							borgMaze[std::make_pair(r + 1, c)] = index++;
						}
						if (maze[r][c + 1] != '#') //check to ur right
						{
							graphNodes.push_back(std::make_pair(r, c + 1));
							borgMaze[std::make_pair(r, c + 1)] = index++;
						}
						if (maze[r][c - 1] != '#') //check to ur left
						{
							graphNodes.push_back(std::make_pair(r, c - 1));
							borgMaze[std::make_pair(r, c - 1)] = index++;
						}
					}
				}
			}
		}

		adjList.resize(graphNodes.size());
		int cNode = 0;
		int index2 = 0;
		for (std::vector<std::pair<int, int>>::iterator it =	graphNodes.begin(); it != graphNodes.end(); it++)
		{

			bfs(cNode, borgMaze);

			index2++;
			++cNode;
		}
		/*std::vector<std::pair<int, int>>::iterator graphit = graphNodes.begin();
		for (int i = 0; i <= graphNodes.size(); i++)
		{
			bfs(i, adjList);
			std::cout << "trying to add edges" << std::endl;
		}*/

		std::cout << "END" << std::endl;
		for (auto y = 0; y < numOfEdges; y++)
		{

		}

		for (std::vector<std::pair<int, int>>::iterator it = neighbours.begin(); it != neighbours.end(); it++)
		{

		}

		//for (auto r = 1; r < numOfRows - 1; r++)
		//{
		//	for (auto c = 1; c < numOfCols - 1; c++)
		//	{
		//		std::cout << "this is c: " << c << std::endl;
		//		std::cout << "this is r: " << r << std::endl;
		//		if (maze[r][c] != '#')
		//		{
		//			if (maze[r + 1][c] != '#') //check under
		//			{
		//				neighbor.push_back(std::make_pair(r + 1, c));
		//			}
		//			if (maze[r - 1][c] != '#') //check over
		//			{
		//				neighbor.push_back(std::make_pair(r - 1, c));
		//			}
		//			if (maze[r][c + 1] != '#') //check to ur right
		//			{
		//				neighbor.push_back(std::make_pair(r, c + 1));
		//			}
		//			if (maze[r][c - 1] != '#') //check to ur left
		//			{
		//				neighbor.push_back(std::make_pair(r, c - 1));
		//			}
		//		}
		//	}
		//}

		std::vector<std::pair<int, int>>::iterator it = neighbours.begin();
		while (it != neighbours.end())
		{
			std::cout << "NEIGHBORS" << std::endl;
			std::cout << it->first << "  ::  " << it->second << std::endl;

			it++;

		}
		std::cout << "\n..............." << std::endl;
		std::map<std::pair<int, int>, int>::iterator iz = borgMaze.begin();
		while (iz != borgMaze.end())
		{
			std::cout << (iz->first).first << "  ::  " << (iz->first).second << std::endl;

			iz++;

		}
		std::cout << borgMaze.size() << std::endl;

		std::cout << "size of graph: " << graphNodes.size() << std::endl;
		std::cout << "adj list size: " << adjList.size();
		std::cout << "just a change: " << std::endl;

		//std::vector<std::set<int>> adjList;


	}
	return 0;
}

