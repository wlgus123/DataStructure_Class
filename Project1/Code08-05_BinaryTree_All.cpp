#include "Common.h"

typedef struct _TreeNode
{
	struct _TreeNode* left = NULL;
	string data;
	struct _TreeNode* right = NULL;
} TreeNode;

Array <TreeNode*> memory;
TreeNode* root = NULL;
Array<string> nameArr = { "블랙핑크", "레드벨벳", "마마무", "에이핑크", "걸스데이", "트와이스" };

void freeMemory()
{
	for (int i = 0; i < len(memory); i++)
		delete memory[i];
}

int main()
{
	TreeNode* node;
	TreeNode* current;	// 현재 노드 작업용(변경되는 값)

	node = new TreeNode;
	node->data = nameArr[0];
	root = node;
	memory.push_back(node);

	for (int i = 1; i < len(nameArr); i++)
	{
		string name = nameArr[i];
		node = new TreeNode;
		node->data = name;

		current = root;
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

	string deleteName = "마마무";
	TreeNode* parent;	// 현재 노드의 부모 노드 작업용(변경되는 값)

	current = root;
	parent = NULL;
	while (true)
	{
		if (deleteName == current->data)
		{
			if (current->left == NULL && current->right == NULL)
			{
				if (parent->left == current)
					parent->left = NULL;
				else
					parent->right = NULL;
				current->data = "None";
			}
			else if (current->left != NULL && current->right == NULL)
			{
				if (parent->left == current)
					parent->left = current->left;
				else
					parent->right = current->left;
				current->data = "None";
			}
			else if (current->left == NULL && current->right != NULL)
			{
				if (parent->left == current)
					parent->left = current->right;
				else
					parent->right = current->right;
				current->data = "None";
			}
			println(deleteName + " 삭제됨.");
			break;
		}

	println("이진 탐색 트리 구성 완료!");
	freeMemory();

	return 0;
}