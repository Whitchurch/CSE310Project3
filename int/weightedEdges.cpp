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
						//Rule out reverse edge scenario
						if (G->startVertex == next->endVertex && G->endVertex == next->startVertex)
						{
							//Don't add anything just return the current node as it.
							return headNode;
						}
						else if (G->startVertex < next->startVertex) //If start node less
						{
							G->next = next;
							headNode = G;
							return headNode;
						}
						else if (G->startVertex == next->startVertex) // If start vettex is equal
						{
							if (G->endVertex < next->endVertex) //check the end vertex
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
						}
						else if (G->startVertex > next->startVertex) // If start vettex is equal
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
					else if (G->startVertex > next->startVertex) // If start vettex is equal
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
				else if (prev != nullptr)
				{
					if (prev->weight < G->weight && G->weight < next->weight)
					{
						G->next = next;
						prev->next = G;
						return headNode;
					}
					else if (G->weight == next->weight)
					{
						//Rule out reverse edge scenario
						if (G->startVertex == next->endVertex && G->endVertex == next->startVertex)
						{
							//Don't add anything just return the current node as it.
							return headNode;
						}
						else if (G->startVertex < next->startVertex) //If start node less
						{
							G->next = next;
							headNode = G;
							return headNode;
						}
						else if (G->startVertex == next->startVertex) // If start vettex is equal
						{
							if (G->endVertex < next->endVertex) //check the end vertex
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
						}
						else if (G->startVertex > next->startVertex) // If start vettex is equal
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
					else if (G->startVertex > next->startVertex) // If start vettex is equal
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
