

#include"Helper_function.h"
#include<iostream>
using namespace std;

void Helper_function::DeleteAdjacenyList(Graph **G,int noOfVertices)
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


void Helper_function::DisplayGraph(Graph ** G, int noOfVertices)
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

void Helper_function::DisplayOddVertex(oddDegreeVertices * head)
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
