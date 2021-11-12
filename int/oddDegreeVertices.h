#pragma once
class oddDegreeVertices
{
public:
	int vertex;
	oddDegreeVertices *next;

	oddDegreeVertices();
	oddDegreeVertices(int vertex);
	static oddDegreeVertices* populateOddDegreeVerticeList(oddDegreeVertices *head,int vertex);
};

