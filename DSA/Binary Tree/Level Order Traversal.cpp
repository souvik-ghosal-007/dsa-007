#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int data)
	{
		val = data;
		left = right = NULL;
	}
};

void inorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void preorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

void levelOrder(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode *node = q.front();
		cout << node->val << " ";
		q.pop();

		if (node->left != NULL) q.push(node->left);
		if (node->right != NULL) q.push(node->right);
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);

	root->left->right = new TreeNode(7);

	cout << "In-Order Traversal -> " << " ";
	inorder(root);
	cout << endl;

	cout << "Post-Order Traversal -> " << " ";
	postorder(root);
	cout << endl;

	cout << "Pre-Order Traversal -> " << " ";
	preorder(root);
	cout << endl;

	cout << "Level - Order Traversal -> " << " ";
	levelOrder(root);
	cout << endl;

	return 0;
}