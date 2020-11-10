#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
Node* insertAtHead(Node*head, int data)
{
	Node* node = new Node(data);

	if (head == nullptr)
	{
		head = node;
	}
	else {
		node->next = head;
		head = node;
	}
	return head;
}

long long  sumElementsOfLinkedList(Node *head)
{
	Node *current = head;
	long long sum = 0;
	while (current != nullptr)
	{
		sum += current->data;
		current = current->next;
	}

	return sum;
}
int maxElement(Node *head)
{
	Node *current = head;
	int maximum = 1;
	while (current != nullptr)
	{
		if (current->data > maximum)
		{
			maximum = current->data;
		}
		current = current->next;
	}
	return maximum;
}
int minElement(Node *head)
{
	Node*current = head;
	int minimum = 10000;
	while (current != nullptr)
	{
		if (current->data < minimum)
		{
			minimum = current->data;
		}
		current = current->next;
	}
	return minimum;
}
int main()
{
	std::ios::sync_with_stdio(false);
	List* list = new List();
	int num;
	while (scanf("%d", &num) == 1)
	{
		Node* head = insertAtHead(list->head, num);
		list->head = head;
	}

	int min = minElement(list->head);
	int max = maxElement(list->head);
	long long sum = sumElementsOfLinkedList(list->head);
	printf("%d %d %lld", min, max, sum);
	return 0;
}