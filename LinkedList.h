
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