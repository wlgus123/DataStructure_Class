#include "Common.h"

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

// 노드 삽입
void insertNode(string findData, string insertData)
{
	Node* node;
	// 첫 번째 노드 앞에 삽입
	if (head->data == findData)
	{
		node = new Node;
		node->data = insertData;
		node->link = head;
		head = node;
		memory.push_back(node);
		return;
	}
	current = head;
	// 중간 노드 삽입
	while (current->link != NULL)
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

	// 마지막 노드 삽입
	node = new Node;
	node->data = insertData;
	current->link = node;
	memory.push_back(node);
}

// 노드 삭제
void deleteNode(string deleteData)
{
	// 현재 데이터가 삭제해야 할 데이터일 때 삭제
	if (head->data == deleteData)
	{
		current = head;
		head = head->link;
		current->data = "None";
		return;
	}

	// 현재 데이터가 삭제해야 할 데이터가 아닐 때
	// 삭제해야 할 데이터 탐색 후 삭제
	current = head;
	while (current->link != NULL)
	{
		pre = current;
		current = current->link;
		if (current->data == deleteData)
		{
			pre->link = current->link;
			current->data = "None";
			return;
		}
	}
}

// 노드 검색
Node* findNode(string findData)
{
	current = head;
	// 현재 데이터가 찾는 데이터면 현재 데이터 반환
	if (head->data == findData)
	{
		return current;
	}
	
	// 현재 데이터가 찾는 데이터가 아니면
	// 반복문으로 데이터 찾기
	while (current->link != NULL)
	{
		current = current->link;
		if (current->data == findData)
		{
			return current;
		}
	}

	// 빈 노드 반환
	return new Node{ "None", NULL };
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

	// 노드 검색
	Node* fNode;
	fNode = findNode("다현");
	println(fNode->data);

	fNode = findNode("쯔위");
	println(fNode->data);

	fNode = findNode("재남");
	println(fNode->data);

	// 메모리 해제
	freeMemory();
	return 0;
}