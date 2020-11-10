#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	double data;
	Node *left;
	Node *right;
	int ht;

	Node(double value)
	{
		this->data = value;
		this->left = nullptr;
		this->right = nullptr;
		this->ht = 0;
	}
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->data == value)
		{
			return true;
		}

		if (value < current->data)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}


	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->data << " ";
		printRecursive(current->right);
	}
	int height(Node*root)
	{
		return (root == nullptr) ? -1 : root->ht;
	}
	Node* singleRightRotate(Node* root)
	{
		Node*left = root->left;
		root->left = left->right;
		left->right = root;
		root->ht = max(height(root->left), height(root->right)) + 1;
		left->ht = max(height(left->left), root->ht) + 1;

		return left;
	}

	Node* singleLeftRotate(Node* root)
	{
		Node* right = root->right;
		root->right = right->left;
		right->left = root;
		root->ht = max(height(root->left), height(root->right)) + 1;
		right->ht = max(height(right->right), root->ht) + 1;

		return right;
	}
	Node* doubleLeftRotate(Node* root)
	{
		root->right = singleRightRotate(root->right);
		return singleLeftRotate(root);
	}

	Node* doubleRightRotate(Node* root)
	{
		root->left = singleLeftRotate(root->left);
		return singleRightRotate(root);
	}

	Node* insert(double data, Node* root)
	{
		if (root == nullptr)
		{
			root = new Node(data);
		}
		else if (data<root->data)
		{
			root->left = insert(data, root->left);
			if (height(root->left) - height(root->right) == 2)
			{
				if (data< root->left->data)
					root = singleRightRotate(root);
				else
					root = doubleRightRotate(root);
			}
		}
		else if (data>root->data)
		{
			root->right = insert(data, root->right);
			if (height(root->right) - height(root->left) == 2)
			{
				if (data>root->right->data)
					root = singleLeftRotate(root);
				else
					root = doubleLeftRotate(root);
			}
		}
		else if (data == root->data)
		{
			cout << data << " already added \n";
		}
		root->ht = max(height(root->left), height(root->right)) + 1;
		return root;
	}
	Node *findMin(Node*root)
	{
		Node*current = root;
		while (current->left != nullptr)
			current = current->left;

		return current;
	}
	int getBalance(Node*root)
	{
		if (root == nullptr)return 0;
		else return height(root->left) - height(root->right);
	}
	Node*remove(double val, Node*root)
	{
		Node *temp;
		if (root == nullptr)
		{
			cout << val << " not found to remove\n";
			return nullptr;
		}
		else if (val<root->data)
		{
			root->left = remove(val, root->left);
		}
		else if (val>root->data)
		{
			root->right = remove(val, root->right);
		}

		else if (root->left != nullptr && root->right != nullptr)
		{
			temp = findMin(root->right);
			root->data = temp->data;
			root->right = remove(temp->data, root->right);
		}
		else if (root->left == nullptr || root->right == nullptr)
		{
			temp = (root->left != nullptr) ? root->left : root->right;
			if (temp == nullptr)
			{
				temp = root;
				root = nullptr;
			}
			else
				*root = *temp;
			delete temp;
		}



		if (root == nullptr)
		{
			return root;
		}

		root->ht = max(height(root->left), height(root->right)) + 1;
		int balance = getBalance(root);

		if (balance>1 && getBalance(root->left) >= 0)
		{
			return singleRightRotate(root);
		}
		if (balance>1 && getBalance(root->left)<0)
		{
			return doubleRightRotate(root);
		}
		if (balance< -1 && getBalance(root->right) <= 0)
		{
			return singleLeftRotate(root);
		}
		if (balance< -1 && getBalance(root->right)>0)
		{
			return doubleLeftRotate(root);
		}

		return root;
	}


public:
	AVLTree()
	{
		root = nullptr;
	}
	void add(double value)
	{
		this->root = insert(value, root);
	}

	void remove(double value)
	{
		this->root = remove(value, root);
	}

	bool contains(double value)
	{
		if (root == nullptr)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == nullptr)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}