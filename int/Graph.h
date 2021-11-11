#pragma once
class Graph
{
	//Define the basic unit of what constitutes a graph data structure. 
public:
	int vertex;
	Graph *next;
	Graph(int vertex);

	Graph();
	static void addEdge();
	static void traverseGraphEdgeList();

};

