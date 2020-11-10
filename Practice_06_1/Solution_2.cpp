#include<bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}
	/*
	class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
	data = d;
	left = NULL;
	right = NULL;
	}
	};

	*/
	void printTopViewUtil(Node* root, int height,
		int hd, map<int, pair<int, int> >& m)
	{
		if (root == NULL)
			return;

		if (m.find(hd) == m.end()) {
			m[hd] = make_pair(root->data, height);
		}
		else {
			pair<int, int> p = (m.find(hd))->second;

			if (p.second > height) {
				m.erase(hd);
				m[hd] = make_pair(root->data, height);
			}
		}

		printTopViewUtil(root->left, height + 1, hd - 1, m);
		printTopViewUtil(root->right, height + 1, hd + 1, m);
	}

	void topView(Node* root)
	{
		map<int, pair<int, int> > m;
		printTopViewUtil(root, 0, 0, m);

		for (map<int, pair<int, int> >::iterator it = m.begin();
			it != m.end(); it++) {
			pair<int, int> p = it->second;
			cout << p.first << " ";
		}
	}

}; //End of Solution

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.topView(root);
	return 0;
}
