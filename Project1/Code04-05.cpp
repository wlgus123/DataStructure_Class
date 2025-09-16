#include "Common.h"

// 구조체 및 전역 변수 선언 부분
typedef struct _Node
{
	string data;
	struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, * current, * pre;
Array<string> dataArray = { "다현", "정연", "쯔위", "사나", "지효" };

// 함수 선언
void printNodes(Node* start)
{
	if (start == NULL)
		return;
	Node* current = start;
	print(current->data);
	while (current->link != NULL)
	{
		current = current->link;
		print(current->data);
	}
	println("");
}

void freeMemory()
{
	for (int i = 0; i < len(memory); i++)
	{
		delete memory[i];
	}
}

// 메인
int main()
{
	Node* node = new Node;
	node->data = dataArray[0];
	head = node;
	memory.push_back(node);

	for (int i = 1; i < len(dataArray); i++)
	{
		string data = dataArray[i];
		pre = node;
		node = new Node;
		node->data = data;
		pre->link = node;
		memory.push_back(node);
	}
	printNodes(head);
	freeMemory();
	return 0;
}