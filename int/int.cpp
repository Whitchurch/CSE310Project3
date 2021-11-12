// int.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "EdgePairs.h"
#include<string>
using namespace std;
int main(int argc, char *argv[])
{
	
	//Step1: Get the filename
	string input;
	
	//Tracking variables
	int noOfVertices = 0;
	int noOfEdges = 0;
	int count = 0;
	Graph **G = nullptr;
	EdgePairs *edgePairs = nullptr;
	//Step2: Read the contents of the  file
	while (getline(cin,input))
	{
		if (noOfVertices == 0 || noOfEdges == 0)
		{
			noOfVertices = (int)input[0] - 48;
			noOfEdges = (int)input[2] - 48;
			G = new Graph*[noOfVertices];
			edgePairs = new EdgePairs[noOfEdges];
		}

		else if (edgePairs != nullptr)
		{
			edgePairs[count].startVertex = input[0] - 48;
			edgePairs[count].endVertex = input[2] - 48;
			count++;
		}

	
	}

	//Set all index headnodes to nullvalues for the Graph Vertexes
	for (int i = 0; i < noOfVertices; i++)
	{
		G[i] = nullptr;
	}

	//Step3: Use a simple hash to insert items into Adjaceny List:
	//Create adjacency list
	for (int i = 0; i < noOfEdges; i++)
	{
		int key = edgePairs[i].startVertex;
		key = key - 1;
		G[key] = Graph::insertIteminGraph(G, key, edgePairs[i].endVertex);
		
	}

	for (int i = 0; i < noOfEdges; i++)
	{
		int key = edgePairs[i].endVertex;
		key = key - 1;
		G[key] = Graph::insertIteminGraph(G, key, edgePairs[i].startVertex);

	}

	//Find out the odd vertices
	for (int i = 0; i < noOfVertices; i++)
	{
		Graph *next;
		next = G[i];
		int count = 0;
		//Display contents of the graph:
		while (next != nullptr)
		{
			count++;
			next = next->next;
		}
		if (count % 2 == 0)
		{
			cout << "Vertex :" << i+1 << " is of even degree" << endl;
		}
		else
		{
			cout << "Vertex :" << i+1 << " is of odd degree" << endl;
		}
		cout << "\n";
	}


	//Display the Graph contents.
	for (int i = 0; i < noOfVertices; i++)
	{
		Graph *next;
		next = G[i];
		//Display contents of the graph:
		while (next != nullptr)
		{
			cout << next->vertex;
			next = next->next;
		}
		cout << "\n";
	}

	
	//Delete objects in the adjacentlist first.
	for (int i = 0; i < noOfVertices; i++)
	{
		Graph *next;
		Graph *store;
		next = G[i];
		//Display contents of the graph:
		while (next != nullptr)
		{
			store = next->next;
			delete next;
			next = store;
		}
	}
	
	//Then delete the array.
	delete[] G;

	// Satisfy the Project's return requirements
	return 0;

}


