#include"EdgePairs.h"
#pragma once
class Stack
{
public:
	EdgePairs reverseNode;
	EdgePairs *node;
	Stack *next;

	Stack();
	static Stack*  PopEdge(Stack *pStack);

};

