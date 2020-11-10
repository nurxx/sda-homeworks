#include <iostream>
#include <string>
#include <unordered_map>
#include<cstring>
using namespace std;

class TrieNode {
public:

	TrieNode(bool end = false) {
		memset(branches, 0, sizeof(branches));
		isEnd = end;
		count = 1;
	}
	TrieNode* branches[26];
	int count;
	bool isEnd;
};

class Trie {
public:
	Trie() {
		this->root = new TrieNode();
	}

	void insert(string s) {
		TrieNode *p = root;
		for (int i = 0; i < s.size(); ++i)
		{
			if (p->branches[s[i] - 'a'] == nullptr)
				p->branches[s[i] - 'a'] = new TrieNode();
			p = p->branches[s[i] - 'a'];
		}
		p->isEnd = true;
	}

	bool search(string key) {
		TrieNode* node = root;
		for (int i = 0; i<key.size(); i++)
			if (node->branches[key[i] - 'a'] == nullptr)
				return false;
			else
			{
				node = node->branches[key[i] - 'a'];
			}
		if (node->isEnd)
		{
			return true;
		}
		else
			return false;
	}

	int wordCount(string key)
	{
		TrieNode*node = root;
		for (int i = 0; i<key.size(); i++)
		{
			if (node->branches[key[i] - 'a'] == nullptr)return false;
			else {
				node = node->branches[key[i] - 'a'];
			}
		}
		if (node->isEnd)
		{
			++node->count;
		}

		return node->count;

	}

	bool startsWith(string prefix) {
		TrieNode* node = root;
		for (int i = 0; i<prefix.size(); i++)
			if (node->branches[prefix[i] - 'a'] == nullptr)
				return false;
			else
			{
				node = node->branches[prefix[i] - 'a'];
			}

		return true;
	}
private:
	TrieNode* root;
};

int main()
{
	int n;
	cin >> n;

	Trie root;
	string str;

	for (int i = 0; i<n; i++)
	{
		cin >> str;
		string prefix = "";
		if (root.search(str) == false)
		{
			if (root.startsWith(str))
			{
				cout << str << endl;
			}
			for (int j = 0; j<str.length(); j++)
			{
				prefix += str[j];
				if (!root.startsWith(prefix))
				{
					cout << prefix << endl;
					break;
				}

			}
			root.insert(str);
		}
		else {
			int count = root.wordCount(str);
			if (count == 1)
				cout << str << endl;
			else {
				cout << str << " " << count << endl;
			}
		}

	}


	return 0;
}
