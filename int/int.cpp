// int.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "Stack.h"
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
		string token[2];
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

			int i_token = 0;
			string delimiter = " ";

			while (i_token < 2)
			{

				token[i_token] = input.substr(0, input.find(delimiter));
				input = input.erase(0, input.find(delimiter) + delimiter.length());
				i_token++;
			}

			if (noOfVertices == 0 || noOfEdges == 0)
			{
				noOfVertices = stoi(token[0]);	// Read the number of vertices
				noOfEdges = stoi(token[1]);		// Read the number of edges				
				G = new Graph*[noOfVertices];
				edgePairs = new EdgePairs[noOfEdges];
			}

			else if (edgePairs != nullptr)
			{
				edgePairs[count].startVertex = stoi(token[0]); // Read in all the edge pairs
				edgePairs[count].endVertex = stoi(token[1]);
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

		//Part 1 of Greedy Algorithm:
		//This section is the code to sort the edges, by insertng them into the linkedlist by increasing weight
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


		//View the sorted Edge List
		Helper_function::displayListValues(headWeightedList);
		
		//Part 2 of Greedy Algorithm:
		//Now  Use Greedy method to add in the perfect matching edges, from the sorted list of edges:
		//Only add in edges , which do not share common vertices:
		weightedEdges *greedyList = nullptr;
		weightedEdges *next;
		weightedEdges *greedyNext;
		weightedEdges *greedyPrev = nullptr;
		
		next = headWeightedList;
		greedyNext = greedyList;
		while (next != nullptr) //Go thru the sorted edge list
		{
			bool canAdd = true;
	
			if (greedyList == nullptr)
			{
				weightedEdges *Gitem = new weightedEdges();
				Gitem->weight = next->weight;
				Gitem->startVertex = next->startVertex;
				Gitem->endVertex = next->endVertex;
				Gitem->next = nullptr;

				greedyList = Gitem;
			}
			else
			{
				greedyNext = greedyList;
				while (greedyNext != nullptr)
				{
	
					if (greedyNext->startVertex != next->startVertex && greedyNext->startVertex != next->endVertex && greedyNext->endVertex != next->startVertex && greedyNext->endVertex != next->endVertex)
					{
						canAdd = true;

					}
					else
					{
						canAdd = false;
						break;
					}
					greedyPrev = greedyNext;
					greedyNext = greedyNext->next;
					
				}

				if (canAdd == true)
				{
					weightedEdges *Gitem = new weightedEdges();
					Gitem->weight = next->weight;
					Gitem->startVertex = next->startVertex;
					Gitem->endVertex = next->endVertex;
					Gitem->next = nullptr;

					greedyPrev->next = Gitem;
				}

				
			}	
			next = next->next;
		}

		//Put in the logic to get the real edges, that represent the virual edge:


		//View the greedy selected edge list
		Helper_function::displayListValues(greedyList);

		//Convert the weighted edge to edgepair type. before feeding into create graph function.
		int greedyCount = 0;
		EdgePairs *EdgesToInsert = nullptr;
		weightedEdges *nextToInsert = nullptr;

		nextToInsert = greedyList;

		while (nextToInsert != nullptr)
		{
			greedyCount++;
			nextToInsert = nextToInsert->next;
		}

		EdgesToInsert = new EdgePairs[greedyCount];

		nextToInsert = greedyList;
		//Convert weighted edges  EdgePair data type.
		for (int i = 0; i < greedyCount; i++)
		{
			EdgesToInsert[i].startVertex = nextToInsert->startVertex;
			EdgesToInsert[i].endVertex = nextToInsert->endVertex;
			nextToInsert = nextToInsert->next;
		}


		//Insert Virtual Edges.
		G = Graph::createGraph(G, greedyCount, EdgesToInsert);
	
		
		//Find Euler circuit.
		Stack *Stack1 = nullptr;
		Stack *Circuit1 = nullptr;
		int startVertexIndex = 0;
		cout << "\n\n" << endl;
		Helper_function::DisplayGraph(G, noOfVertices);
		Stack1 = Helper_function::FindEulerCircuit(G, Stack1, Circuit1,startVertexIndex,noOfVertices);


		//--- Section to delete all data structures and free up the memory--------------------------------///
		//Delete the Adjaceny Matrix used by Floyd-Warshall Algorithm
		Helper_function::DeleteAdjacenyMatrix(M, noOfVertices);

		Helper_function::DeleteAdjacenyMatrix(M_reduced, noOfVertices);


		//Display Graph
		Helper_function::DisplayGraph(G, noOfVertices);

		//Display odd Graph
		Helper_function::DisplayOddVertex(head);

		//Delete odd VertexList
		Helper_function::DeleteOddVertex(head);

		//Delete objects in the adjacentlist first.
		Helper_function::DeleteAdjacenyList(G, noOfVertices);

		//Delete weighted edge lists both greedy and the full sorted weighted edge list.
		Helper_function::DeleteWeightedVertex(greedyList);
		Helper_function::DeleteWeightedVertex(headWeightedList);

		//Then delete the array.
		delete[] G;
		delete[] edgePairs;
		delete[] EdgesToInsert;
		// Satisfy the Project's return requirements
		return 0;
	}
	catch (...)
	{
		cout << "Exception occured in main()" << endl;
	}

}


