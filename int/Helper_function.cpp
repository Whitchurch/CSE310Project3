

#include"Helper_function.h"
#include<iostream>
using namespace std;

const int Infinity = 1000000;
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
				M[i][j] = Infinity;
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
			//G[key]
		}

		return nullptr;
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
