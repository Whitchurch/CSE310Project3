#include "Graph.h"
#include "oddDegreeVertices.h"
#include<iostream>

using namespace std;
oddDegreeVertices::oddDegreeVertices()
{
	this->vertex = 0;
	this->next = nullptr;
}

oddDegreeVertices::oddDegreeVertices(int vertex)
{
	this->vertex = vertex;
	this->next = nullptr;
}


oddDegreeVertices* oddDegreeVertices::populateOddDegreeVerticeList(oddDegreeVertices *head, int vertex)
{
	try
	{
		oddDegreeVertices *next;
		next = head;
		if (head == nullptr)
		{
			head = new oddDegreeVertices(vertex);
			return head;
		}
		else
		{


			while (next->next != nullptr)
			{

				next = next->next;

			}
			next->next = new oddDegreeVertices(vertex);
			return head;

		}
	}
	catch (...)
	{
		cout << "Exception: oddDegreeVertices* oddDegreeVertices::populateOddDegreeVerticeList(oddDegreeVertices *head, int vertex)" << endl;
	}


}

oddDegreeVertices* oddDegreeVertices::createOddDegreeVerticesList(Graph **G,oddDegreeVertices * head, int noOfVertices)
{
	try
	{
		for (int i = 0; i < noOfVertices; i++)
		{
			Graph *next;
			next = G[i];
			int count = 0;


			while (next != nullptr)
			{
				count++;
				next = next->next;
			}
			if (count % 2 == 0)
			{
				/*cout << "Vertex :" << i+1 << " is of even degree" << endl;*/
			}
			else
			{
				/*cout << "Vertex :" << i+1 << " is of odd degree" << endl;*/
				head = oddDegreeVertices::populateOddDegreeVerticeList(head, i + 1);
			}

		}
		return head;
	}
	catch (...)
	{
		cout << "Exception: oddDegreeVertices* oddDegreeVertices::createOddDegreeVerticesList(Graph **G,oddDegreeVertices * head, int noOfVertices)" << endl;
	}


}
