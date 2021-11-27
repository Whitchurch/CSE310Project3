#include"Graph.h"
#include"Stack.h"
#include "oddDegreeVertices.h"
#include "weightedEdges.h"
#pragma once
class Helper_function
{
public:
	static void DeleteAdjacenyList(Graph ** G, int noOfVertices);
	static void DisplayGraph(Graph **G, int noOfVertices);
	static void DisplayOddVertex(oddDegreeVertices *next);
	static int** CreateAdjacenyMatrix(int **M, int noOfVertices);
	static int** InitializeAdjacenyMatrix(int **M, int noOfVertices);
	static int** PopulateAdjacenyMatrix(int **M, int noOfVertices,Graph **G);
	static void DeleteAdjacenyMatrix(int **M, int noOfVertices);
	static void DisplayAdjacenyMatix(int **M, int noOfVertices);
	static int** FloydWarshalAlgorithm(int **M, int noOfVertices);
	static void displayListValues(weightedEdges *W);
	static void displayGreedyListValues(weightedEdges *W);
	static void DeleteOddVertex(oddDegreeVertices *OddVertexList);
	static void DeleteWeightedVertex(weightedEdges *W);
	//static Stack* FindEulerCircuit(Graph ** G, Stack *Stack, Stack *pCircuit, int startVertexIndex, int noOfVertices);
	static Stack* FindEulerCircuit(Graph ** G, Stack * pStack, Stack * pCircuit, int startVertexIndex, int noOfVertices);
	static void expandVirtualNode(Stack *pCircuit, weightedEdges *greedyList);
	static void DisplayFloydWarshallMatix(int **M, int noOfVertices,oddDegreeVertices *head);
};