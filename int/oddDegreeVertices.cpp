#include "oddDegreeVertices.h"

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
