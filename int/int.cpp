// int.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "EdgePairs.h"
#include "weightedEdges.h"
#include "oddDegreeVertices.h"
#include "Helper_function.h"
#include<string>
using namespace std;
int main(int argc, char *argv[])
{
	try
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
		while (getline(cin, input))
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
		G = Graph::initializeGraph(G, noOfVertices);

		//Step3: Use a simple hash to insert items into Adjaceny List:
		//Create adjacency list
		G = Graph::createGraph(G, noOfEdges, edgePairs);

		//Find out the odd vertices
		//Create the oddvertex list
		oddDegreeVertices *head = nullptr;

		//Create the AdjacenyList
		head = oddDegreeVertices::createOddDegreeVerticesList(G, head, noOfVertices);

		
		//Create Adjaceny Matrix to be used by the Floyd-Warshall Algorithm
		int **M = nullptr;
		M = Helper_function::CreateAdjacenyMatrix(M, noOfVertices);

		//Initalize the Adjaceny Matrix with infinity value;
		M = Helper_function::InitializeAdjacenyMatrix(M, noOfVertices);

		//Populate the Adjacent Matri with the edge relationship
		M = Helper_function::PopulateAdjacenyMatrix(M, noOfVertices,G);

		//Display the Adjacency Matrix BEFORE FLOYD-WARSHALL ALGORITHM:
		Helper_function::DisplayAdjacenyMatix(M, noOfVertices);

		//Calculate the Pair-Wise shortest path using Floyd-Warshall Algorithm
		M = Helper_function::FloydWarshalAlgorithm(M, noOfVertices);

		//Display the Adjacency Matrix AFTER FLOYD-WARSHALL ALGORITHM:
		Helper_function::DisplayAdjacenyMatix(M, noOfVertices);


		int **M_reduced = nullptr;
		M_reduced = Helper_function::CreateAdjacenyMatrix(M_reduced, noOfVertices);

		for (int i = 0; i < noOfVertices; i++)
		{
			for (int j = 0; j < noOfVertices; j++)
			{
				M_reduced[i][j] = 0;
			}
		}

		oddDegreeVertices *startVertex = head;
		oddDegreeVertices *endVerted = head;

		while (startVertex != nullptr)
		{
			while (endVerted != nullptr)
			{
				M_reduced[(startVertex->vertex) - 1][(endVerted->vertex) - 1] = M[(startVertex->vertex) - 1][(endVerted->vertex) - 1];
				endVerted = endVerted->next;
			}
			endVerted = head;
			startVertex = startVertex->next;
		}
		
		//Display the reduced subset of the Floyd Warshal Matrix
		Helper_function::DisplayAdjacenyMatix(M_reduced, noOfVertices);

		weightedEdges *headWeightedList = nullptr;

		for (int i = 0; i < noOfVertices; i++)
		{
			for (int j = 0; j < noOfVertices; j++)
			{
				if (M_reduced[i][j] != 0) // This implies an weight and edge exists. Recostruct the start and end vertex, from the matrix position meta-data
				{
					weightedEdges *w = new weightedEdges();
					w->weight = M_reduced[i][j];
					w->startVertex = i + 1;
					w->endVertex = j + 1;

					//Insert the edges in a sorted manner.
					headWeightedList = headWeightedList->insertIteminGraph(headWeightedList,w);

				}
			}
		}



		//Now  Use Greedy method to add in the perfect matching edges, from the sorted list of edges:
		//Only add in edges , which do not share common vertices:
		weightedEdges *greedyList = nullptr;
		weightedEdges *next;
		weightedEdges *prev;
		next = headWeightedList;
		bool canAdd = false;
		while (next != nullptr)
		{
			canAdd = false;
			if (greedyList == nullptr)
			{
				greedyList = next;
			}
			else
			{
				while (greedyList != nullptr)
				{
					if (greedyList->startVertex != next->startVertex && greedyList->startVertex != next->endVertex && greedyList->endVertex != next->startVertex && greedyList->endVertex != next->endVertex)
					{
						canAdd = true;
					}
					greedyList = greedyList->next;
				}

				//Only add if edge shares no edge with existing edges.
				if (canAdd == true)
				{
					greedyList = next;
				}
				
			}	
			next = next->next;
		}


		//Insert Virtual Edges.
		//Find Euler circuit.



		//--- Section to delete all data structures and free up the memory--------------------------------///
		//Delete the Adjaceny Matrix used by Floyd-Warshall Algorithm
		Helper_function::DeleteAdjacenyMatrix(M, noOfVertices);

		Helper_function::DeleteAdjacenyMatrix(M_reduced, noOfVertices);


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
	catch (...)
	{
		cout << "Exception occured in main()" << endl;
	}

}


