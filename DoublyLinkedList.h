#pragma once

#include <cstdarg>

// DOUBLY LINKED LIST CLASS (Templated)
template <class T>
class DoublyLinkedList {
private:

	// NODE CLASS
	class Node {
	public:
		T data;
		Node *pNext;
		Node *pPrev;
		Node(T item, Node *next = nullptr, Node *previous = nullptr) :data(item), pNext(next), pPrev(previous) {}
	};

	// GET NODE METHOD
	Node *getNode(unsigned pos) const {
		Node *curr = pHead;
		for (unsigned x = 1; x < pos; x++) curr = curr->pNext;
		return curr;
	}

	// LINKED LIST MEMBERS
	unsigned size;
	Node *pHead;
	Node *pTail;

public:
	DoublyLinkedList() :size(0), pHead(nullptr), pTail(nullptr) {}
	~DoublyLinkedList()
	{
		Node *next, *curr = pHead;
		while (curr != nullptr) {
			next = curr->pNext;
			delete curr;
			curr = next;
		}
	}

	// IS EMPTY METHOD
	bool isEmpty() const { return size == 0; }

	// GET SIZE METHOD
	unsigned getSize() const { return size; }

	// ADD HEAD 
	void addHead(T item) {
		Node *newNode = new Node(item, pHead);

		if (isEmpty())		// if the list is empty then head is thenew node and tail is the new node
		{
			pHead = newNode;
			pTail = pHead;
		}
		else                // if list is not empty, we set the next of the new node to the previous head
		{
			newNode->pNext = pHead;
			pHead->pPrev = newNode;
			pHead = newNode;
			newNode->pPrev = nullptr;
		}
		size++;
	}

	// ADD TAIL 
	void addTail(T item) {
		Node *newTailNode = new Node(item, pHead);

		if (i