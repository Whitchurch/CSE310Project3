#pragma once
class weightedEdges
{
public:
	int weight;
	int startVertex;
	int endVertex;
	weightedEdges *next;
	
	weightedEdges();

	static weightedEdges* insertIteminGraph(weightedEdges* headNode, weightedEdges* G);


};

