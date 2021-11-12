#include "Graph.h"

Graph::Graph(int vertex)
{
	this->vertex = vertex;
	this->next = nullptr;
}


Graph::Graph()
{
	this->next = nullptr;
	this->vertex = 0;
}

Graph * Graph::insertIteminGraph(Graph **G,int key,int vertex)
{
	Graph *next;
	Graph *prev;
	Graph *headNode;
	prev = nullptr;
	next = G[key];
	headNode = G[key];

	
	//If current node is empty in Graph, directly assign the item
	if (next == nullptr)
	{
		next = new Graph(vertex);
		headNode = next;
		return headNode;
	}
	else
	{
		while (next != nullptr)
		{
			if (prev == nullptr)
			{
				if (vertex > next->vertex)
				{
					prev = next;
					next = next->next;

					if (next == nullptr)
					{
						next = new Graph(vertex);
						prev->next = next;
						return headNode;
					}

				}
				else if (vertex < next->vertex)
				{
					Graph *newItem = new Graph(vertex);
					newItem->next = next;
					headNode = newItem;
					return headNode;
				}

			}
			else if (prev != nullptr)
			{
				if (prev->vertex < vertex && vertex < next->vertex)
				{
					Graph *newItem = new Graph(vertex);

					newItem->next = next;
					prev->next = newItem;
					return headNode;
				}
				else
				{
					prev = next;
					next = next->next;
					if (next == nullptr)
					{
						next = new Graph(vertex);
						prev->next = next;
						return headNode;
					}
				}
			}
			


		}


	}

	//else
	//{

	//	while (next != nullptr)
	//	{
	//		//if item greater than prev, but less than next insert it inbetween.
	//		if (prev != nullptr)
	//		{
	//			if (prev->vertex < vertex < next->vertex)
	//			{
	//				Graph *newItem = new Graph(vertex);
	//				newItem->next = next;
	//				prev->next = newItem;
	//			}
	//			else
	//			{
	//				prev = next;
	//				next = next->next;
	//			}
	//		}
	//		else
	//		{
	//			if (vertex < next->vertex)
	//			{
	//				Graph *newItem = new Graph(vertex);
	//				newItem->next = next;
	//				headNode = newItem;
	//			}
	//			else
	//			{
	//				prev = next;
	//				next = next->next;
	//				if (next == nullptr)
	//				{
	//					next = new Graph(vertex);
	//					return headNode;
	//				}

	//			}
	//		}

	//		
	//	}

	//}

	return headNode;
}

Graph ** Graph::initializeGraph(Graph ** G, int noOfVertices)
{
	for (int i = 0; i < noOfVertices; i++)
	{
		G[i] = nullptr;
	}
	return G;
}

void Graph::addEdge()
{
}

void Graph::traverseGraphEdgeList()
{
}
