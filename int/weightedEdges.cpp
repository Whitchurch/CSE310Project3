#include "weightedEdges.h"



weightedEdges::weightedEdges()
{
	this->endVertex = 0;
	this->startVertex = 0;
	this->weight = 0;
	this->next = nullptr;
}

weightedEdges * weightedEdges::insertIteminGraph(weightedEdges* headNode,weightedEdges* G)
{
	weightedEdges *next;
	weightedEdges *prev;
	prev = nullptr;
	next = headNode;


		if (next == nullptr)
		{
			headNode = G;
			return headNode;
		}
		else
		{
			while (next != nullptr)
			{
				if (prev == nullptr)
				{
					if (G->weight > next->weight)
					{
						prev = next;
						next = next->next;

						if (next == nullptr)
						{
							next = G;
							prev->next = next;
							return headNode;
						}

					}
					else if (G->weight < next->weight)
					{
						G->next = next;
						headNode = G;
						return headNode;
					}
					else if (G->weight == next->weight)
					{
						if (G->startVertex < next->startVertex)
						{
							G->next = next;
							headNode = G;
							return headNode;
						}
					}
					/*else if (G->startVertex == next->startVertex)
					{
						if (G->endVertex < next->endVertex)
						{
							G->next = next;
							headNode = G;
							return headNode;
						}
						else if (G->endVertex > next->endVertex)
						{
							prev = next;
							next = next->next;

							if (next == nullptr)
							{
								next = G;
								prev->next = next;
								return headNode;
							}
						}
					}*/
				}
				else if (prev != nullptr)
				{
					if (prev->weight < G->weight && G->weight < next->weight)
					{
						G->next = next;
						prev->next = G;
						return headNode;
					}
					else
					{
						prev = next;
						next = next->next;
						if (next == nullptr)
						{
							next = G;
							prev->next = next;
							return headNode;
						}
					}
				}
			}
		}

		return headNode;


}
