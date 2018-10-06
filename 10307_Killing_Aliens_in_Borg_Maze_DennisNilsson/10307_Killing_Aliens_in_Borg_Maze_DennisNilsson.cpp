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

typedef std::pair<int, int> intPair; //fucking no work, all of a sudden it does

typedef std::vector<intPair> vii; //fukkk
//typedef std::vector<std::pair<int, int>> vii;

#define _CRT_SECURE_NO_DEPRECATE

#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it !=(c).end(); it++)

int find(int u);
void bfs(int s);
//void mstKruskals();
void mstPrim();


/*Adjacency List, usually in form of C++ STL vector<vii> AdjList, withvii deﬁned as:
typedef pair<int, int> ii;
typedef vector<ii> vii; // our data type shortcuts
In Adjacency List, we have a vector of V vertices and for each vertex v,
we store another vector that contains pairs of (neighboring vertex and it’s edge weight) that have connection to v.
If the graph is unweighted, simply store weight = 0 or drop this second attribute.
With Adjacency List, we can enumerate the list of neighbors of a vertex v eﬃciently.
If there are k neighbors of v, this enumeration isO(k).
As this is one of the most common operations in most graph algorithms,
it is advisable to stick with Adjacency List as your default choice.
*/



void bfs(int s)
{
	std::vector<std::vector<std::pair<int, int>>> adjList;

	std::queue<int> q; //order the sequence of visitation

	std::map<int, int> dist;
	//record if a vertex has been visited or not and also the distance of each vertex from the source vertex

	//this solves single source shortest path problem

	q.push(s);
	dist[s] = 0;

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

	int testCases;
	std::cin >> testCases;
	for (auto i = 0; i < testCases; i++)
	{
		int numOfRows, numOfCols, numOfNodes, startIndexRow, startIndexColumn;

		std::string line;
		std::vector<std::string> maze;
		std::vector<std::pair<int, int>> aliens;
		std::vector<std::pair<int, int>> neighbours;


		std::vector<std::pair<int, std::pair<int, int>>> egdes; // I want to use this


		std::map<int, std::pair<int, int>> nei;
		std::set<std::pair<int, int>> al;
		std::set<int, std::pair<int, int>> well;

		std::cin >> numOfCols >> numOfRows;
		std::getline(std::cin, line);

		numOfNodes = numOfRows * numOfCols;

		std::vector<std::vector<std::pair<int, int>>> adjList(numOfNodes);

		std::vector<std::pair<int, int>> alienNodes, graphNodes, possibleNeighbors, neighbor;
		std::map<std::pair<int, int>, int> map;
		int index = 0;

		for (auto j = 0; i < numOfRows; i++)
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
					//aliens.push_back(std::pair<int, int>(r, c));
					//al.insert(std::pair<int,int>(r, c));
					//well.insert(index, std::pair<int, int>(r, c));
					//map_name.insert(make_pair(make_pair(arg1, arg2), arg3));
					//al.insert(std::make_pair(r, c));
					//al.insert(std::pair<int,int>(r, c));

					graphNodes.push_back(std::make_pair(r, c));
					alienNodes.push_back(std::make_pair(r, c));
					map[std::make_pair(r, c)] = index++;
					std::cout << "ALIEN     " << " column: " << c << "  row: " << r << std::endl;
				}
				if (maze[r][c] == 'S')
				{
					std::cout << "START    " << "in column: " << c << " on row: " << r << std::endl;
					startIndexRow = r;
					startIndexColumn = c;
					//al.insert(std::make_pair(startIndexRow, startIndexColumn));
					//al.insert(std::pair<int, int>(r, c));
					graphNodes.push_back(std::make_pair(r, c));
					alienNodes.push_back(std::make_pair(r, c));
					map[std::make_pair(r, c)] = index++;

				}
				if (maze[r][c] != '#')   //uhuh
				{
					if (( c >= 1 && c < numOfCols - 1 ) && ( r >= 1 && r < numOfRows - 1 ))
					{
						std::cout << "this is c: " << c << std::endl;
						std::cout << "this is r: " << r << std::endl;
						if (maze[r][c] != '#')
						{
							if (maze[r + 1][c] != '#') //check under
							{
								neighbor.push_back(std::make_pair(r + 1, c));
							}
							if (maze[r - 1][c] != '#') //check over
							{
								neighbor.push_back(std::make_pair(r - 1, c));
							}
							if (maze[r][c + 1] != '#') //check to ur right
							{
								neighbor.push_back(std::make_pair(r, c + 1));
							}
							if (maze[r][c - 1] != '#') //check to ur left
							{
								neighbor.push_back(std::make_pair(r, c - 1));
							}
						}
					}

					std::cout << "KORSGARD " << " column: " << c << "  row: " << r << std::endl;

				}
				if (maze[r][c] == ' ')
				{
					graphNodes.push_back(std::make_pair(r, c));
					map[std::make_pair(r, c)] = index++;
					std::cout << "SPACE    " << " column: " << c << "  row: " << r << std::endl;

					/*al.insert(std::make_pair(r - 1, c));
					al.insert(std::make_pair(r + 1, c));
					al.insert(std::make_pair(r, c - 1));
					al.insert(std::make_pair(r, c + 1));*/
				}
			}
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

		std::vector<std::pair<int, int>>::iterator it = neighbor.begin();
		while (it != neighbor.end())
		{
			std::cout << "NEIGHBORS" << std::endl;
			std::cout << it->first << "  ::  " << it->second << std::endl;

			it++;

		}
		std::cout << "\n..............." << std::endl;
		std::map<std::pair<int, int>, int>::iterator iz = map.begin();
		while (iz != map.end())
		{
			std::cout << ( iz->first ).first << "  ::  " << ( iz->first ).second << std::endl;

			iz++;

		}
		std::cout << map.size() << std::endl;

		std::cout << "size of graph: " << graphNodes.size() << std::endl;


		//std::vector<std::set<int>> adjList;


	}
	return 0;
}

