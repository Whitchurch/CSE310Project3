

#include"Helper_function.h"
#include<iostream>
using namespace std;

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
