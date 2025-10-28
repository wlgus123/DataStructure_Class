#include "Common.h"

typedef struct _TreeNode
{
	struct _TreeNode* left = NULL;
	string data;
	struct _TreeNode* right = NULL;
} TreeNode;

int main()
{
	TreeNode* root;
	
	TreeNode* node1 = new TreeNode;
	node1->data = "È­»ç";
	root = node1;

	TreeNode* node2 = new TreeNode;
	node2->data = "¼Ö¶ó";
	node1->left = node2;

	TreeNode* node3 = new TreeNode;
	node3->data = "¹®º°";
	node1->right = node3;

	TreeNode* node4 = new TreeNode;
	node4->data = "ÈÖÀÎ";
	node2->left = node4;

	TreeNode* node5 = new TreeNode;
	node5->data = "ÂêÀ§";
	node2->right = node5;

	TreeNode* node6 = new TreeNode;
	node6->data = "¼±¹Ì";
	node3->left = node6;

	println(root->data);
	println(root->left->data + " " + root->right->data);
	println(root->left->left->data + " " + root->left->right->data + " " + root->right->left->data);

	return 0;
}