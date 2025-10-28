#include "Common.h"

#include "Common.h"

typedef struct _TreeNode // 이진트리 노드
{
	struct _TreeNode* left = NULL;
	string data;
	struct _TreeNode* right = NULL;
} TreeNode;

Array <TreeNode*> memory;
TreeNode* root;
TreeNode* rootBook, * rootAuth;
Array <Array <string>> bookAry = { {"어린왕자", "생떽쥐베리"},
	{"이방인", "까뮈"}, {"부활", "톨스토이"}, {"신곡", "단테"},
	{"돈키호테", "세르반테스"}, {"동물농장", "조지오웰"}, {"데미안", "헤르만헤세"},
	{"파우스트", "괴테"}, {"대지", "펄벅"} };

void freeMemory()
{
	for (int i = 0; i < len(memory); i++)
	{
		delete memory[i];
	}
}

int main()
{
	srand((int)time(NULL)); // bookAry를 랜덤하게 섞기
	for (int i = 0; i < len(bookAry) * 100; i++)
	{
		int n1 = rand() % len(bookAry);
		int n2 = rand() % len(bookAry);
		swap(bookAry[n1], bookAry[n2]);
	}

	TreeNode* node;
	TreeNode* current; // 현재 노드 작업용 (변경)

	//// 책 이름 트리 ////
	node = new TreeNode;
	node->data = bookAry[0][0];
	rootBook = node;
	memory.push_back(node);

	for (int i = 0; i < len(bookAry); i++)
	{
		string name = bookAry[i][0];
		node = new TreeNode;
		node->data = name;

		current = rootBook;
		while (true)
		{
			if (name < current->data)
			{
				if (current->left == NULL)
				{
					current->left = node;
					break;
				}
				current = current->left;
			}
			else
			{
				if (current->right == NULL)
				{
					current->right = node;
					break;
				}
				current = current->right;
			}
		}
		memory.push_back(node);
	}
	println("책 이름 트리 구성 완료!");

	//// 작가 이름 트리 ////
	node = new TreeNode;
	node->data = bookAry[0][1];
	rootAuth = node;
	memory.push_back(node);

	for (int i = 1; i < len(bookAry); i++)
	{
		string name = bookAry[i][1];
		node = new TreeNode;
		node->data = name;

		current = rootAuth;
		while (true)
		{
			if (name < current->data)
			{
				if (current->left == NULL)
				{
					current->left = node;
					break;
				}
				current = current->left;
			}
			else
			{
				if (current->right == NULL)
				{
					current->right = node;
					break;
				}
				current = current->right;
			}
		}
		memory.push_back(node);
	}
	println("작가 이름 트리 구성 완료!");

	//// 책 이름 및 작가 이름 검색 ////
	string bookOrAuth, findName;
	input(bookOrAuth, "책검색(1), 작가검색(2)-->");
	input(findName, "검색할 책 또는 작가-->");

	if (bookOrAuth == "1")
		root = rootBook;
	else
		root = rootAuth;

	current = root;
	while (true)
	{
		if (findName == current->data)
		{
			println(findName + " 찾음.");
			break;
		}
		else if (findName < current->data)
		{
			if (current->left == NULL)
			{
				println(findName + " 트리에 없음.");
				break;
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				println(findName + " 트리에 없음.");
				break;
			}
			current = current->right;
		}
	}
	freeMemory();
}