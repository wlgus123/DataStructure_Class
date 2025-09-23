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

// 노드 삭제
void deleteNode(string deleteData)
{
	Node* last;
	if (head->data == deleteData)
	{
		current = head;
		head = head->link;
		last = head;
		// 마지막 노드를 찾으면 반복 종료
		while (last->link != current)
		{
			last = last->link;
		}
		last->link = head;
		current->data = "None";	// 현재 노드 제거
		return;
	}

	current = head;
	while (current->link != head)
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
	if (head->data == findData)
	{
		return current;
	}
	while (current->link != head)
	{
		current = current->link;
		if (current->data == findData)
		{
			return current;
		}
	}
	return new Node{ "None", NULL };
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

	// 노드 삭제
	deleteNode("문별");
	printNodes(head);

	deleteNode("지효");
	printNodes(head);

	deleteNode("재남");	// 없는 데이터는 무시
	printNodes(head);

	// 노드 검색
	Node* fNode;
	fNode = findNode("다현");
	println(fNode->data);

	fNode = findNode("재남");	// 없는 데이터는 새로운 노드 None을 만들어서 반환
	println(fNode->data);
	
	freeMemory();

	return 0;
}