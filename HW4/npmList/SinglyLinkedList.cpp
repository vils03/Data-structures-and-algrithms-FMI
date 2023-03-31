#include "SinglyLinkedList.h"

void SinglyLinkedList::copyFrom(const SinglyLinkedList& other) {
	Node* iter = other.head;

	while (iter)
	{
		pushBack(iter->data);
		iter = iter->next;
	}
}

void SinglyLinkedList::free()
{
	Node* iter = head;

	while (iter)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}

	head = tail = nullptr;
}

SinglyLinkedList::SinglyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
{
	head = nullptr;
	tail = nullptr;
	copyFrom(other);
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SinglyLinkedList::~SinglyLinkedList()
{
	free();
}

void SinglyLinkedList::pushFront(const int& el)
{
	Node* newNode = new Node(el);

	if (!head)
	{
		head = tail = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
}

void SinglyLinkedList::pushBack(const int& el)
{
	Node* newNode = new Node(el);

	if (!tail)
	{
		head = tail = newNode;
		return;
	}

	tail->next = newNode;
	tail = newNode;
}

void SinglyLinkedList::popFront()
{
	if (!head)
		throw "Empty list!";

	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}

	Node* toDelete = head;
	head = head->next;
	delete toDelete;
}

const int& SinglyLinkedList::front() const
{
	if (!head)
		throw "Empty list!";

	return head->data;
}

const int& SinglyLinkedList::back() const
{
	if (!tail)
		throw "Empty list!";

	return tail->data;
}

void SinglyLinkedList::print() const
{
	Node* iter = head;

	while (iter)
	{
		cout << iter->data << ' ';
		if (iter->next)
			cout << "->" << ' ';
		iter = iter->next;
	}
}

