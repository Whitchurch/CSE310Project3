#include "Stack.h"
#include "reverseEdgeStack.h"
Stack::Stack()
{
	this->CircuitGenerationComplete = false;
	this->next = nullptr;
	this->node = nullptr;
}

Stack* Stack::PopEdge(Stack *pStack)
{
	EdgePairs edgeToReturn;
	edgeToReturn.startVertex = pStack->node->endVertex;
	edgeToReturn.endVertex = pStack->node->startVertex;

	Stack *prev;
	Stack *next;

	prev = pStack;
	next = pStack->next;
	delete(prev);
	pStack = next;
	if (pStack == nullptr)
	{
		pStack = new Stack();
		pStack->reverseNode = edgeToReturn;
	}
	else
	{
		pStack->reverseNode = edgeToReturn;
	}
	

	return(pStack);
}

