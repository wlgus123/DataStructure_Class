#include <iostream>
#include <vector>

using namespace std;

#define Array vector
#define print(data) cout << data << " ";
#define println(data) cout << data << endl;

typedef struct _Node
{
	string data;
	struct _Node* link = NULL;
} Node;

Array <Node*> memory;

int main()
{
	Node* node1 = new Node;
	node1->data = "자료구조";

	Node* node2 = new Node;
	node2->data = "알고리즘";
	node1->link = node2;

	Node* node3 = new Node;
	node3->data = "C언어";
	node2->link = node3;

	memory.push_back(node1);
	memory.push_back(node2);
	memory.push_back(node3);

	// 일반 출력 방법
	for (int i = 0; i < memory.size(); i++)
	{
		println(memory[i]->data);
	}

	println("");

	// 링크를 사용한 방법
	Node* curNode = node1->link;
	while (curNode != NULL)
	{
		println(curNode->data);
		// 다음 노드를 가리킴
		curNode = curNode->link;
	}

	for (int i = 0; i < memory.size(); i++)
	{
		delete memory[i];
	}
}