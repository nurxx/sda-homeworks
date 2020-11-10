#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

struct List {
	Node *head;
	Node *tail;

	List()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

};
void insertAtTail(List *list, int data)
{
	Node*last = new Node(data);
	if (list->head== nullptr)
	{
		list->head = last;
		list->tail = last;
	}
	else {
		list->tail->next = last;
		list->tail = last;
	}
}
int findPos(List *list)
{
	Node*current = list->head;
	while (current != current->next)
	{
		current->next = current->next->next;
		current = current->next;
	}
	return current->data;
}



int main()
{
	int n;
	cin >> n;
	List *l=new List();
	for (int i = 1; i <= n; i++)
	{
		insertAtTail(l, i);
	}
	l->tail->next = l->head;
	cout << findPos(l) << endl;
	system("pause");
	return 0;
}