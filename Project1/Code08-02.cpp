#include "Common.h"

typedef struct _TreeNode
{
	struct _TreeNode* left = NULL;
	string data;
	struct _TreeNode* right = NULL;
} TreeNode;

void preOrder(TreeNode* node)
{
	if (node == NULL)
		return;
	print(node->data + "->");
	preOrder(node->left);
	preOrder(node->right);
}

void inOrder(TreeNode* node)
{
	if (node == NULL)
		return;
	preOrder(node->left);
	print(node->data + "->");
	preOrder(node->right);
}

void postOrder(TreeNode* node)
{
	if (node == NULL)
		return;
	preOrder(node->left);
	preOrder(node->right);
	print(node->data + "->");
}

int main()
{
	TreeNode* root;

	TreeNode* node1 = new TreeNode;
	node1->data = "화사";
	root = node1;

	TreeNode* node2 = new TreeNode;
	node2->data = "솔라";
	node1->left = node2;

	TreeNode* node3 = new TreeNode;
	node3->data = "문별";
	node1->right = node3;

	TreeNode* node4 = new TreeNode;
	node4->data = "휘인";
	node2->left = node4;

	TreeNode* node5 = new TreeNode;
	node5->data = "쯔위";
	node2->right = node5;

	TreeNode* node6 = new TreeNode;
	node6->data = "선미";
	node3->left = node6;

	print("전위 순회: ");
	preOrder(root);
	println("끝");

	print("중위 순회: ");
	inOrder(root);
	println("끝");

	print("후위 순회: ");
	postOrder(root);
	println("끝");

	return 0;
}