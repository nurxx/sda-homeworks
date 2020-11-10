#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node*left;
	Node*right;
	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct Tree {
	Node*root;

	Tree()
	{
		this->root = nullptr;
	}

	void insertData(int data, Node*leaf)
	{
		if (data < leaf->data)
		{
			if (leaf->left != nullptr)
			{
				insertData(data, leaf->left);
			}
			else {
				leaf->left = new Node(data);
			}
		}
		else if (data > leaf->data)
		{
			if (leaf->right != nullptr)
			{
				insertData(data, leaf->right);
			}
			else {
				leaf->right = new Node(data);
			}
		}
	}
	void insert(int data)
	{
		if (this->root != nullptr)
		{
			insertData(data, this->root);
		}
		else {
			this->root = new Node(data);
		}
	}

	bool contains(int data, Node*root)
	{
		if (root != nullptr) {
			if (data == root->data) {
				return true;
			}
			if (data < root->data) {
				return contains(data, root->left);
			}
			else {
				return contains(data, root->right);
			}
		}

		return false;

	}
	bool contains(int data)
	{
		return contains(data, this->root);
	}

};
int countAll(Node*root)
{
	int count = 0;
	if (root != nullptr)
	{
		count++;
		if (root->left != nullptr) {
			count += countAll(root->left);
		}
		if (root->right != nullptr) {
			count += countAll(root->right);
		}
	}
	return count;
}
struct Pair {
	int a;
	int b;
	Pair(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};

int main() {
	Tree *tree = new Tree();
	int x;
	cin >> x;
	tree->insert(x);
	int n;
	cin >> n;
	vector<Pair>vec;
	vec.reserve(n);
	int c, d;
	for (int i = 0; i<n; i++)
	{
		cin >> c >> d;
		vec.push_back(Pair(c, d));
	}
	for (int i = 0; i<n; i++)
	{
		if (tree->contains(vec[i].a)>0) { tree->insert(vec[i].b); }
	}
	cout << countAll(tree->root) << endl;
	return 0;
}