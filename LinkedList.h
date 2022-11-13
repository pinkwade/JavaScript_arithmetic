
#pragma once
#include <iostream>
#include <string>
using namespace std;


template <class T>
class LinkedList
{
private:
	class Node
	{
	public:
		Node(T v, Node* n = NULL) : value(v), next(n) {}
		T value;
		Node * next;
	};

	Node *head;
	Node *tail;
	unsigned int size;

public:

	LinkedList(): head(NULL), tail(NULL), size(0) {}
	~LinkedList() 
	{
		Node * temp = head, *nextnode;
		while (temp != NULL)
		{
			nextnode = temp->next;
			delete temp;
			temp = nextnode;
		}
	}

	unsigned int size()const
	{
		return size;
	}

	bool isEmpty()const
	{
		return (size == 0);
	}

	void addHead(T item)
	{
		head = new Node(item, head);
		if (tail == NULL)
		{
			tail = head;
		}
		size++;
	}

	T removeHead()
	{
		Node* oldNode = head;
		T returnValue = head->value;
		head = head->next;
		if (head == NULL)
		{
			tail = NULL;
		}
		size--;
		delete oldNode;
		return returnValue;
	}

	T retreiveHead()const
	{
		return head->value;
	}

	void addTail(T item)
	{
		if (isEmpty())
		{
			addHead(item);
		}
		else
		{
			tail = tail->next = new Node(item);
			size++;
		}

	}

	T removeTail()
	{
		if (head == tail)
		{
			return removeHead;
		}
		Node *preTail = head;
		T returnValue = tail->value;
		while (preTail->next != tail)
		{
			preTail = preTail->next;
		}
		preTail->next = NULL;
		delete tail;
		tail = preTail;
		size--;
		return returnValue;
	}

	T retreiveTail()const
	{
		return tail->value;
	}

	void add(unsigned int x, T item)
	{
		if (x == 1)
		{
			addHead(item);
		}
		else if (x == size() + 1)
		{
			addTail(item)
		}
		else
		{