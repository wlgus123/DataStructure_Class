#include "Common.h"

typedef struct _Node
{
	string data;
	struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, * current, * pre;
Array <string> dataArray = { "다현", "정연", "쯔위", "사나", "지효" };

// 노드 삽입
void insertNode(string findData, string insertData)
{
	Node* node;
	Node* last;
	if (head->data == findData)
	{
		node = new Node;
		node->data = insertData;
		node->link = head;
		last = head;
		while (last->link != head)
			last = last->link;
		last->link = node;
		head = node;
		memory.push_back(node);
		return;
	}
	current = head;
	while (current->link != head)
	{
		pre = current;
		current = current->link;
		if (current->data == findData)
		{
			node = new Node;
			node->data = insertData;
			node->link = current;
			pre->link = node;
			memory.push_back(node);
			return;
		}
	}
	node = new Node;
	node->data = insertData;
	current->link = node;
	node->link = head;
	memory.push_back(node);
}

// 노드 출력
void printNodes(Node* start)
{
	if (start == NULL)
		return;
	Node* current = start;
	print(current->data);
	while (current->link != start)
	{
		current = current->link;
		print(current->data);
	}
	println("");
}

// 노드 할당 해제
void freeMemory()
{
	for (int i = 0; i < len(memory); i++)
	{
		delete memory[i];
	}
}

int main()
{
	Node* node = new Node;
	node->data = dataArray[0];
	head = node;
	node->link = head;
	memory.push_back(node);

	// 두 번째 이후 노드부터 시작
	for (int i = 1; i < len(dataArray); i++)
	{
		string data = dataArray[i];
		pre = node;
		node = new Node;
		node->data = data;
		pre->link = node;
		node->link = head;
		memory.push_back(node);
	}

	// 노드 삽입
	insertNode("다현", "화사");	// 다현 앞에 화사 삽입
	printNodes(head);

	insertNode("사나", "솔라");	// 사나 앞에 솔라 삽입
	printNodes(head);

	insertNode("재남", "문별");	// 재남은 리스트에 없음. 따라서 맨 뒤에 삽입
	printNodes(head);
	
	freeMemory();

	return 0;
}