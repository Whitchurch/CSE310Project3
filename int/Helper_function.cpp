

#include"Helper_function.h"
#include<iostream>
using namespace std;

const int Infinity = 99999;
const int selfLoop = 0;
void Helper_function::DeleteAdjacenyList(Graph **G,int noOfVertices)
{
	try
	{
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
	}
	catch (...)
	{
		cout << "Exception: void Helper_function::DeleteAdjacenyList(Graph **G,int noOfVertices)" << endl;
	}

}


void Helper_function::DisplayGraph(Graph ** G, int noOfVertices)
{
	try
	{
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
	}
	catch (...)
	{
		cout << "Exception: void Helper_function::DisplayGraph(Graph ** G, int noOfVertices)" << endl;
	}

}

void Helper_function::DisplayOddVertex(oddDegreeVertices * head)
{
	try
	{
		//Display the items in the oddVertex List:
		oddDegreeVertices *next = head;
		while (next != nullptr)
		{
			cout << next->vertex;
			next = next->next;
		}
		cout << "\n";
	}
	catch (...)
	{
		cout << "Exception: void Helper_function::DisplayOddVertex(oddDegreeVertices * head)" << endl;
	}

}

int ** Helper_function::CreateAdjacenyMatrix(int ** M, int noOfVertices)
{
	try
	{
		M = new int*[noOfVertices];
		for (int i = 0; i < noOfVertices; i++)
		{
			M[i] = new int[noOfVertices];
		}
		return M;
	}
	catch (...)
	{
		cout << "Exception: int ** Helper_function::CreateAdjacenyMatrix(int ** M, int noOfVertices)" << endl;
	}

}

int ** Helper_function::InitializeAdjacenyMatrix(int ** M, int noOfVertices)
{
	try
	{
		for (int i = 0; i < noOfVertices; i++)
		{
			for (int j = 0; j < noOfVertices; j++)
			{
				if (i == j)
				{
					M[i][j] = selfLoop;
				}
				else
				{
					M[i][j] = Infinity;
				}
				
			}
		}

		return M;
	}
	catch (...)
	{
		cout << "Exception: int ** Helper_function::InitializeAdjacenyMatrix(int ** M, int noOfVertices)" << endl;
	}

}




int ** Helper_function::PopulateAdjacenyMatrix(int ** M, int noOfVertices, Graph ** G)
{
	try
	{
		for (int key = 0; key < noOfVertices; key++)
		{
			Graph *next = G[key];
			while (next != nullptr)
			{
				int destinationVertex = next->vertex;
				M[key][destinationVertex-1] = 1;
				next = next->next;
			}
		}

		return M;
	}
	catch (...)
	{
		cout << "Exception: int ** Helper_function::PopulateAdjacenyMatrix(int ** M, int noOfVertices, Graph ** G)" << endl;
	}

}

void Helper_function::DeleteAdjacenyMatrix(int ** M, int noOfVertices)
{
	try
	{
		for (int i = 0; i < noOfVertices; i++)
		{

			delete[] M[i];
		}

		delete[] M;
	}
	catch (...)
	{
		cout << "Exception: void Helper_function::DeleteAdjacenyMatrix(int ** M, int noOfVertices)" << endl;
	}

}

void Helper_function::DisplayAdjacenyMatix(int ** M, int noOfVertices)
{
	for (int i = 0; i < noOfVertices; i++)
	{
		for (int j = 0; j < noOfVertices; j++)
		{
			cout << M[i][j]<<"\t";
		}
		cout << "\n";
	}
}

int ** Helper_function::FloydWarshalAlgorithm(int ** M, int noOfVertices)
{
	try
	{
		int k = noOfVertices; // intermediate nodes we plan to visit
		int i = noOfVertices; // starting node.
		int j = noOfVertices; // destination node.

		for (int k = 0; k < noOfVertices; k++)
		{
			for (int i = 0; i < noOfVertices; i++)
			{
				for (int j = 0; j < noOfVertices; j++)
				{
					if (M[i][j] > (M[i][k] + M[k][j]))
					{
						M[i][j] = (M[i][k] + M[k][j]);
					}
				}
			}
		}

		return M;
	}
	catch (...)
	{
		cout << "Exception: int ** Helper_function::FloydWarshalAlgorithm(int ** M, int noOfVertices)" << endl;
	}
	
}

void Helper_function::displayListValues(weightedEdges * W)
{
	try
	{
		weightedEdges *greedyList = W;
		//Code to view the greedy list
		while (greedyList != nullptr)
		{
			//cout << headWeightedList->weight;
			cout << greedyList->startVertex;
			cout << greedyList->endVertex << endl;

			greedyList = greedyList->next;
		}
	}
	catch (...)
	{
		cout << "Exception: Helper_function::displayListValues(weightedEdges * W)" << endl;
	}


}

void Helper_function::DeleteOddVertex(oddDegreeVertices * OddVertexList)
{
	oddDegreeVertices *prev;
	oddDegreeVertices *next;

	prev = OddVertexList;
	next = OddVertexList;

	while (next != nullptr)
	{
		prev = next;
		next = next->next;
		delete(prev);
		prev = next;
	}

}

void Helper_function::DeleteWeightedVertex(weightedEdges * W)
{
	weightedEdges *prev;
	weightedEdges *next;

	prev = W;
	next = W;

	while (next != nullptr)
	{
		prev = next;
		next = next->next;
		delete(prev);
		prev = next;
	}

}

void Helper_function::FindEulerCircuit(Graph ** G, Stack * pStack, int startVertexIndex,int noOfVertices)
{
	Graph *vertexToRemoveNext = nullptr;
	Graph *vertexToRemovePrev = nullptr;

	Stack *nextStack;
	Stack *prevStack;

	nextStack = pStack;
	prevStack = pStack;

	int endVertexIndex = G[startVertexIndex]->vertex;

	EdgePairs *newEdgeToIsert = new EdgePairs();
	newEdgeToIsert->startVertex = startVertexIndex + 1;
	newEdgeToIsert->endVertex = endVertexIndex;

	if (nextStack == nullptr)
	{
		nextStack = new Stack();
		nextStack->node = newEdgeToIsert;
		pStack = nextStack;
	}
	else
	{
		while (nextStack != nullptr)
		{
			prevStack = nextStack;
			nextStack = nextStack->next;
			if (nextStack == nullptr)
			{
				nextStack = new Stack();
				nextStack->node = newEdgeToIsert;
				prevStack->next = nextStack;
				nextStack = nextStack->next;
			}
		}
	}

	//Write code to remove the vertex
	vertexToRemoveNext = G[startVertexIndex];
	vertexToRemovePrev = G[startVertexIndex];
	vertexToRemoveNext = vertexToRemoveNext->next;
	delete(vertexToRemovePrev);
	G[startVertexIndex] = vertexToRemoveNext;

	//Reverse  the start and end nodes, to remove the reverse from the Adjaceny List:
	int tempStartVertex = 0;
	int tempEndVertex = 0;

	tempStartVertex = endVertexIndex - 1;
	tempEndVertex = startVertexIndex + 1;

	//Write code to remove the vertex
	vertexToRemoveNext = G[tempStartVertex];
	vertexToRemovePrev = nullptr;
	while (vertexToRemoveNext != nullptr)
	{
		if (vertexToRemoveNext->vertex == tempEndVertex)
		{
			if (vertexToRemovePrev == nullptr)
			{
				vertexToRemovePrev = vertexToRemoveNext->next;
				delete(vertexToRemoveNext);
				G[tempStartVertex] = vertexToRemovePrev;
				break;
			}
			else
			{
				vertexToRemovePrev->next = vertexToRemoveNext->next;
				delete(vertexToRemoveNext);
				//G[tempStartVertex] = vertexToRemovePrev;
				break;
			}

		}

		vertexToRemovePrev = vertexToRemoveNext;
		vertexToRemoveNext = vertexToRemoveNext->next;
	}
	Helper_function::DisplayGraph(G, noOfVertices);
	if (G == nullptr)
	{
		return;
	}
	else
	{
		FindEulerCircuit(G, pStack, tempStartVertex, noOfVertices);
	}
	

}

		
