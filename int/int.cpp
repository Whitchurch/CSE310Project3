// int.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "EdgePairs.h"
#include "oddDegreeVertices.h"
#include "Helper_function.h"
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
			noOfVertices = (int)input[0] - 48;	// Read the number of vertices
			noOfEdges = (int)input[2] - 48;		// Read the number of edges				
			G = new Graph*[noOfVertices];
			edgePairs = new EdgePairs[noOfEdges];
		}

		else if (edgePairs != nullptr)
		{
			edgePairs[count].startVertex = input[0] - 48; // Read in all the edge pairs
			edgePairs[count].endVertex = input[2] - 48;
			count++;
		}

	
	}

	//Set all index headnodes to nullvalues for the Graph Vertexes
	G = Graph::initializeGraph(G,noOfVertices);

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
	//Create the oddvertex list
	oddDegreeVertices *head = nullptr;
	
	//Create the AdjacenyList
	head = oddDegreeVertices::createOddDegreeVerticesList(G, head, noOfVertices);

	//Display Graph
	Helper_function::DisplayGraph(G, noOfVertices);
	
	//Display odd Graph
	Helper_function::DisplayOddVertex(head);

	//Delete objects in the adjacentlist first.
	Helper_function::DeleteAdjacenyList(G, noOfVertices);
	
	//Then delete the array.
	delete[] G;

	// Satisfy the Project's return requirements
	return 0;

}


