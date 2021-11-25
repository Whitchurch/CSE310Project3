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
	static void DeleteOddVertex(oddDegreeVertices *OddVertexList);
	static void DeleteWeightedVertex(weightedEdges *W);
	static void FindEulerCircuit(Graph ** G, Stack *Stack, int startVertexIndex, int noOfVertices);
};