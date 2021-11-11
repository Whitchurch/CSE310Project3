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
		}

	
	}


	//int vertex[4] = {1,2,3,4};
	//
	//// Put in code to test out the Graph Data Structure
	//Graph** G = new Graph*[4];
	//
	//G[0] = new Graph(2);
	//G[1] = new Graph(3);
	//G[1]->next = new Graph(5);
	//G[2] = new Graph(4);
	//G[3] = new Graph(1);


	//for (int i = 0; i < 4; i++)
	//{
	//	Graph *next;
	//	next = G[i];
	//	//Display contents of the graph:
	//	while (next != nullptr)
	//	{
	//		cout << next->vertex;
	//		next = next->next;
	//	}
	//	cout << "\n";
	//}

	//
	////Delete objects in the adjacentlist first.
	//for (int i = 0; i < 4; i++)
	//{
	//	Graph *next;
	//	Graph *store;
	//	next = G[i];
	//	//Display contents of the graph:
	//	while (next != nullptr)
	//	{
	//		store = next->next;
	//		delete next;
	//		next = store;
	//	}
	//}
	//
	////Then delete the array.
	//delete[] G;

	//// Satisfy the Project's return requirements
	//return 0;

}


