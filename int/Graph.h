#pragma once
class Graph
{
	//Define the basic unit of what constitutes a graph data structure. 
public:
	int vertex;
	Graph *next;
	Graph(int vertex);

	Graph();
	static Graph* insertIteminGraph(Graph **G,int key, int vertex);
	static void addEdge();
	static void traverseGraphEdgeList();

};

