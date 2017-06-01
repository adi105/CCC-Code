#pragma once
#include <iostream>
using namespace std;

class Graph
{
	int V;    // No. of vertices
	int adj[4][4] = { {0} };
	void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void DFS();    // prints DFS traversal of the complete graph
};

Graph::Graph(int V)
{
	this->V = V;
}

void Graph::addEdge(int v, int w)
{
	adj[v][w] = 1;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	for (int index1 = v; index1 < V; index1++) {
		for (int index2 = 0; index2 < V; index2++) {
			if (adj[index1][index2] == 1  && visited[index2] == false) {
				DFSUtil(index2, visited);
			}
		}
	}
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal
	// starting from all vertices one by one
	DFSUtil(0, visited);
	
}
