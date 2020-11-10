#include <iostream>
#include <algorithm>
#include <vector>

int countLinkedList[1235] = { 0 };
int countArray[1235] = { 0 };

using namespace std;
struct Node {
	int data;
	Node*next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}

};
struct List {
	Node*head;

	List()
	{
		this->head = nullptr;
	}
};
Node *insertAtTail(Node *head, int data)
{
	Node*last = new Node(data);
	if (head == nullptr)
	{
		head = last;
	}
	else {
		Node*current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = last;
	}

	return head;
}
void freeLinkedList(Node *head)
{
	while (head)
	{
		Node*current = head;
		head = head->next;

		delete current;
	}
}
int traverse(Node*head, long long *arr, int size)
{
	Node*current = head;
	while (current != nullptr)
	{
		countLinkedList[current->data]++;
		current = current->next;
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= 1234)
		{
			countArray[arr[i]]++;
		}
	}
	int pairs = 0;
	bool flag = false;
	for (int i = 1; i <= 1234; i++)
	{

		if (countLinkedList[i] != countArray[i] && countLinkedList[i]>0 && countArray[i]>0)
		{
			pairs++;
		}
		if (countLinkedList[i] == countArray[i] && countLinkedList[i]>0 && countArray[i]>0)
		{
			pairs++;
			flag = true;
		}

	}
	if (flag)pairs--;
	return pairs;
}



int main()
{
	List *list = new List();
	int n;
	cin >> n;
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		Node*head = insertAtTail(list->head, data);
		list->head = head;
	}
	int p;
	cin >> p;
	long long *arr = new long long[p];
	for (int i = 0; i < p; i++)
	{
		cin >> arr[i];
	}
	cout << traverse(list->head, arr, p) << endl;

	freeLinkedList(list->head);
	delete[]arr;

	return 0;
}

