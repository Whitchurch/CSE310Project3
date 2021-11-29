

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

		oddDegreeVertices *greedyList = head;
		//Code to view the greedy list
		cout << "The odd-degree vertices in G: O = { ";
		while (greedyList != nullptr)
		{
			//cout << headWeightedList->weight;
			cout << greedyList->vertex << " ";
			greedyList = greedyList->next;
		}
		cout << "}"<<endl;
		cout << "\n";
		//oddDegreeVertices *next = head;
		//while (next != nullptr)
		//{
		//	cout << next->vertex;
		//	next = next->next;
		//}
		//cout << "\n";
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

void Helper_function::displayGreedyListValues(weightedEdges * W)
{
	try
	{
		weightedEdges *greedyList = W;
		//Code to view the greedy list
		cout << "The greedy perfect matching in O: M = {";
		while (greedyList != nullptr)
		{
			//cout << headWeightedList->weight;
			cout <<" ("<<greedyList->startVertex<<",";
			cout << greedyList->endVertex <<")";

			greedyList = greedyList->next;
		}
		cout << " }"<<endl;
	}
	catch (...)
	{
		cout << "Exception: Helper_function::displayListValues(weightedEdges * W)" << endl;
	}
}

void Helper_function::DeleteOddVertex(oddDegreeVertices * OddVertexList)
{
	try
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
	catch (...)
	{
		cout << "Exception: Helper_function::DeleteOddVertex(oddDegreeVertices * OddVertexList)" << endl;
	}


}

void Helper_function::DeleteWeightedVertex(weightedEdges * W)
{
	try
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
	catch (...)
	{
		cout << "Exception: Helper_function::DeleteWeightedVertex(weightedEdges * W)" << endl;
	}


}

int turns = 0;
int turns_level1 = 1;
Stack* Helper_function::FindEulerCircuit(Graph ** G, Stack * pStack, Stack * pCircuit, int startVertexIndex,int noOfVertices, weightedEdges * EdgesToInsert)
{

	try
	{
		
		Graph *vertexToRemoveNext = nullptr;
		Graph *vertexToRemovePrev = nullptr;

		Stack *nextStack;
		Stack *prevStack;

		nextStack = pStack;
		prevStack = pStack;

		if (G[startVertexIndex] == nullptr)
		{
			return pStack;
		}

		int endVertexIndex = G[startVertexIndex]->vertex;

		EdgePairs *newEdgeToIsert = new EdgePairs();
		newEdgeToIsert->startVertex = startVertexIndex + 1;
		newEdgeToIsert->endVertex = endVertexIndex;
		
		weightedEdges *traverseEdgePairs = EdgesToInsert;
		while (traverseEdgePairs != nullptr)
		{if(newEdgeToIsert->startVertex == traverseEdgePairs->startVertex && newEdgeToIsert->endVertex == traverseEdgePairs->endVertex|| newEdgeToIsert->startVertex == traverseEdgePairs->endVertex && newEdgeToIsert->endVertex == traverseEdgePairs->startVertex)
		{
			newEdgeToIsert->isVirtual = traverseEdgePairs->isVirtual;
		}
			traverseEdgePairs = traverseEdgePairs->next;
		}

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
				prevStack = pStack;
				nextStack = nextStack->next;
				if (nextStack == nullptr) //Insert head first to make it easier to reverse stuff later
				{
					nextStack = new Stack();
					nextStack->node = newEdgeToIsert;
					nextStack->next = prevStack;
					pStack = nextStack;
					//prevStack->next = nextStack;
					//nextStack = nextStack->next;
					break;
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
		//cout << "\n\n" << endl;
		//Helper_function::DisplayGraph(G, noOfVertices);
		if (G == nullptr)
		{
			return pStack;
		}
		else
		{

			pStack = FindEulerCircuit(G, pStack, pCircuit, tempStartVertex, noOfVertices, EdgesToInsert);

			
			if (pStack->CircuitGenerationComplete == true)
			{

				return pStack;
			}
			Stack *Stack1 = nullptr;
			Stack *Circuit1 = nullptr;
			Stack1 = pStack;
			Circuit1 = pCircuit;
			while (Stack1 != nullptr)
			{
				// Pop the reversed edge
				Stack1 = Stack1->PopEdge(Stack1);
				Stack *temp = Stack1;
				//Add the reversed edge into the Circuit
				if (Circuit1 == nullptr)
				{
					Circuit1 = new Stack();
					Circuit1->reverseNode = temp->reverseNode;
				}
				else
				{
					Stack *prev;
					Stack *next;

					prev = Circuit1;
					next = Circuit1;
					while (next != nullptr)
					{
						prev = next;
						next = next->next;
						if (next == nullptr)
						{
							next = new Stack();
							next->reverseNode = temp->reverseNode;
							prev->next = next;
							break;
						}

					}

				}


				//cout << temp->reverseNode.startVertex << temp->reverseNode.endVertex;
				//Do a Euler pass on the new Startvertex. If any exist.
				int endvertexStack1 = (temp->reverseNode.endVertex - 1);
				//cout << "I Crash after this point 1:" << endl;
				Stack1 = Helper_function::FindEulerCircuit(G, Stack1, Circuit1, endvertexStack1, noOfVertices, EdgesToInsert);
				//cout << "I did not crash point 2:" << endl;
				if (Stack1->CircuitGenerationComplete == true)
				{

					return Stack1;
				}

				Stack1 = temp;
				if (Stack1->node == nullptr)
				{

					Stack1 = Circuit1;
					Stack1->CircuitGenerationComplete = true;
					return Stack1;
				}
			}
		}
	}
	catch (...)
	{
		cout << "Exception: Helper_function::FindEulerCircuit(Graph ** G, Stack * pStack, Stack * pCircuit, int startVertexIndex,int noOfVertices)" << endl;
	}
	
	

}

void Helper_function::expandVirtualNode(Stack * pCircuit, weightedEdges * greedyList)
{
	try
	{
		weightedEdges *traverser = nullptr;
		traverser = greedyList;
		bool canExpand = false;
		while (traverser != nullptr)
		{
			if (pCircuit->reverseNode.isVirtual == true)
			{

				if (pCircuit->reverseNode.startVertex == traverser->startVertex && pCircuit->reverseNode.endVertex == traverser->endVertex|| pCircuit->reverseNode.startVertex == traverser->endVertex && pCircuit->reverseNode.endVertex == traverser->startVertex)
				{
					if (traverser->weight > 1)
					{
						canExpand = true;
					}
					else
					{
						canExpand = false;
					}


				}
			}


			if (canExpand == true)
			{
				weightedEdges *tempFlipper = nullptr;
				weightedEdges *prevtempFlipper = nullptr;
				while (traverser->expansionSubPaths != nullptr)
				{
					//Put the reversal logic here:
					//Swap individual elements.
					//Create a insert in head type deal, for the reversal.

					//cout << "\t" << "(" << traverser->expansionSubPaths->startVertex << "," << traverser->expansionSubPaths->endVertex << ")" << endl;
					//traverser->expansionSubPaths = traverser->expansionSubPaths->next;

					if (pCircuit->reverseNode.startVertex == traverser->expansionSubPaths->endVertex || pCircuit->reverseNode.endVertex == traverser->expansionSubPaths->startVertex)
					{
						//cout << "Flip this entry" << endl;
						
						tempFlipper = new weightedEdges[traverser->weight];
						for (int i = 0; i < traverser->weight; i++)
						{
							tempFlipper[i].startVertex = traverser->expansionSubPaths->endVertex;
							tempFlipper[i].endVertex = traverser->expansionSubPaths->startVertex;
							traverser->expansionSubPaths = traverser->expansionSubPaths->next;
							if (traverser->expansionSubPaths == nullptr)
							{
								break;
							}
						}

						for (int i = (traverser->weight-1); i >= 0; i--)
						{
							cout << "\t" << "(" << tempFlipper[i].startVertex << "," << tempFlipper[i].endVertex << ")" << endl;
						}
						
						
					}
					else
					{
						cout << "\t" << "(" << traverser->expansionSubPaths->startVertex << "," << traverser->expansionSubPaths->endVertex << ")" << endl;
						traverser->expansionSubPaths = traverser->expansionSubPaths->next;
					}
					
				}
				break;
			}

			traverser = traverser->next;
		}

		if (canExpand == false)
		{
			cout <<"\t"<<"("<<pCircuit->reverseNode.startVertex<<","<< pCircuit->reverseNode.endVertex<<")"<< endl;
		}
	}
	catch (...)
	{
		cout << "Exception: Helper_function::expandVirtualNode(Stack * pCircuit, weightedEdges * greedyList)" << endl;
	}

}

void Helper_function::DisplayFloydWarshallMatix(int ** M, int noOfVertices,oddDegreeVertices *head)
{

	oddDegreeVertices *next = nullptr;
	oddDegreeVertices *next2ndLevel = nullptr;
	next = head;
	int xAxisCount = 0;
	cout << "Results of Floyd-Warshall on O:" << endl;

	if (head == nullptr)
	{
		return;
	}
	
	//Print the table:
	cout << "     " << "| ";
	while (next != nullptr)
	{
		int digitCount = 0;
		int numberToFigureout = next->vertex;
		do {
			numberToFigureout /= 10;
			++digitCount;
		} while (numberToFigureout != 0);

		if (digitCount == 1)
		{
			cout << "   " << next->vertex;
		}
		else if (digitCount == 2)
		{
			cout << "  " << next->vertex;
		}
		else if (digitCount == 3)
		{
			cout << " " << next->vertex;
		}
		else if (digitCount > 3)
		{
			cout << "" << next->vertex << "  " << "|" << " ";
		}
		
		xAxisCount++;
		next = next->next;
	}
	//for (int i = 0; i < noOfVertices; i++)
	//{
	//	cout << "   " << i;
	//}
	cout << endl;
	cout << "--- -" << "+-";
	for (int i = 0; i < xAxisCount; i++)
	{
		cout << " ---";
	}
	cout << endl;

	next = head;
	
	while (next != nullptr)
	{
		int digitCount = 0;
		int numberToFigureout = next->vertex;
		do {
			numberToFigureout/= 10;
			++digitCount;
		} while (numberToFigureout != 0);

		if (digitCount == 1)
		{
			cout << "  " << next->vertex << "  " << "|" << " ";
		}
		else if (digitCount == 2)
		{
			cout << " " << next->vertex << "  " << "|" << " ";
		}
		else if (digitCount == 3)
		{
			cout << "" << next->vertex << "  " << "|" << " ";
		}
		else if (digitCount > 3)
		{
			cout << "" << next->vertex << "  " << "|" << " ";
		}
		
		next2ndLevel = head;
			while (next2ndLevel != nullptr)
			{
				cout << "   " << M[next->vertex - 1][next2ndLevel->vertex-1];
				next2ndLevel = next2ndLevel->next;
			}
			
		
		cout << endl;
		next = next->next;
	}

	//for (int i = 0; i < noOfVertices; i++)
	//{
	//	cout << "  " << i<<"  "<<"|"<<" ";
	//	for (int j = 0; j < noOfVertices; j++)
	//	{
	//		cout << "   "<<j;
	//	}
	//	cout << endl;
	//}

	//for (int i = 0; i < noOfVertices; i++)
	//{
	//	for (int j = 0; j < noOfVertices; j++)
	//	{
	//		cout << M[i][j] << "\t";
	//	}
	//	cout << "\n";
	//}
}

		
