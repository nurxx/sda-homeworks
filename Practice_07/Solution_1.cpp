#include <iostream>

using namespace std;
int counter = 0;
struct Node {
	int data;
	Node*left;
	Node*right;
	Node(int data)
	{
		this->data = data;
		this->right = nullptr;
		this->left = nullptr;
	}

};
struct BinaryTree {
	Node*root;
	BinaryTree()
	{
		this->root = nullptr;
	}

};
void insertAt(int key, Node*leaf)
{
	if (key < leaf->data)
	{
		if (leaf->left != nullptr)
		{
			insertAt(key, leaf->left);
		}
		else {
			leaf->left = new Node(key);
		}
	}
	else if (key >= leaf->data)
	{
		if (leaf->right != nullptr)
		{
			insertAt(key, leaf->right);
		}
		else {
			leaf->right = new Node(key);
		}
	}
}

void insert(int key, BinaryTree*tree)
{
	if (tree->root != nullptr)
	{
		insertAt(key, tree->root);
	}
	else {
		tree->root = new Node(key);
	}
}
int height(Node*root)
{
	if (root == nullptr)
	{
		return -1;
	}
	else
	{
		int left = height(root->left);
		int right = height(root->right);

		if (left > right)return left + 1;
		else return right + 1;
	}
}
double traverse(Node*root, int depth, int level)
{
	double sum = 0;
	if (root == nullptr || depth > level)
	{
		return 0;
	}
	if (depth == level) {
		sum += root->data;
	}
	if (root->left != nullptr)
	{
		sum += traverse(root->left, depth + 1, level);
	}
	if (root->right != nullptr)
	{
		sum += traverse(root->right, depth + 1, level);
	}
	return sum;
}
int  SumNodesByLevel(Node*root, int level)
{
	return traverse(root, 0, level);
}
double getNodesCountInLevel(Node*root, int current, int desired)
{
	if (root == nullptr)return 0;
	if (current == desired)return 1;
	else {
		return getNodesCountInLevel(root->left, current + 1, desired) +
			getNodesCountInLevel(root->right, current + 1, desired);
	}
}
int main()
{
	BinaryTree*tree = new BinaryTree();
	int key;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> key;
		insert(key, tree);
	}
	int levels = height(tree->root) + 1;
	for (int i = 0; i < levels; i++)
	{
		printf("%.2lf \n", SumNodesByLevel(tree->root, i) / getNodesCountInLevel(tree->root, 0, i));
	}

	return 0;
}