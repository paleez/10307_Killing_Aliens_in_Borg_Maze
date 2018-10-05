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
	std::vector<std::vector<std::pair<int,int>>> adjList;

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

		

		std::cin >> numOfCols >> numOfRows;
		std::getline(std::cin, line); //first row is only walls

		numOfNodes = numOfRows * numOfCols;

		std::vector<std::vector<std::pair<int, int>>> adjList(numOfNodes);
		
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
					aliens.push_back(std::pair<int, int>(r, c));
				}
				else if (maze[r][c] == 'S')
				{
					startIndexRow = r;
					startIndexColumn = c;
				}
				else if (maze[r][c] == '#')
				{

				}
				else if (maze[r][c] == ' ')
				{

				}
			}
		}

		
		std::vector<std::set<int>> adjList(numOfNodes);
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

