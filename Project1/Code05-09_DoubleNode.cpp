#include "Common.h"

typedef struct _DoubleNode
{
	struct _DoubleNode* pLink = NULL;	// 앞쪽 링크
	string data;
	struct _DoubleNode* nLink = NULL;	// 뒷쪽 링크
} DoubleNode;

Array <DoubleNode*> memory;
DoubleNode* head, * current, * pre;
Array <string> dataArray = { "다현", "정연", "쯔위", "사나", "지효" };

void printDoubleNodes(DoubleNode* start)
{
	DoubleNode* current = start;
	if (current->nLink == NULL)
		return;
	print("정방향: ");
	print(current->data);
	while (current->nLink != NULL)
	{
		current = current->nLink;
		print(current->data);
	}
	println("");
	print("역방향: ");
	print(current->data);
	while (current->pLink != NULL)
	{
		current = current->pLink;
		print(current->data);
	}
	println("");
}

void freeMemory()
{
	for (int i = 0; i < len(memory); i++)
		delete memory[i];
}

int main()
{
	DoubleNode* node = new DoubleNode;
	node->data = dataArray[0];
	head = node;
	memory.push_back(node);

	for(int i = 1; i < len(dataArray); i++)
	{ 
		string data = dataArray[i];
		pre = node;
		node = new DoubleNode;
		node->data = data;
		pre->nLink = node;
		node->pLink = pre;
		memory.push_back(node);
	}
	printDoubleNodes(head);

	freeMemory();

	return 0;
}