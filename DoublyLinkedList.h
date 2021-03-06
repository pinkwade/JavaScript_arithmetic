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

		if (isEmpty()) {
			pHead = newTailNode;
			pTail = pHead;
		}
		else {
			newTailNode->pPrev = pTail;
			pTail->pNext = newTailNode;
		}

		pTail = newTailNode;
		pTail->pNext = nullptr;
		size++;
	}

	// ADD
	void add(unsigned pos, T item) {
		if (pos == 1)
		{
			addHead(item);
		}
		else if (pos == size + 1)
		{
			addTail(item);
		}
		else
		{

			Node *prev = getNode(pos - 1);
			Node *next = getNode(pos);
			Node *newNode = new Node(item);
			prev->pNext = newNode;
			next->pPrev = newNode;

			newNode->pPrev = prev;
			newNode->pNext = next;

			size++;
		}
	}

	// RETRIEVE HEAD
	T retrieveHead() const
	{
		return pHead->data;
	}

	// RETRIEVE TAIL
	T retrieveTail() const
	{
		return pTail->data;
	}

	// RETRIEVE (No clue how this method works)
	T retrieve(unsigned pos) const
	{
		return
			(pos == size ? retrieveTail() : getNode(pos)->data);
	}

	// REAMOVE HEAD
	T removeHead() {
		// This is the data value that we are returning
		T returnData = pHead->data;

		// If pHead contains something aka points to something
		if (pHead != NULL) {
			// Get the next node to head
			Node *nextNode = pHead->pNext;

			// If next node is not equal to null then
			if (nextNode != NULL) {
				// We set the Nextnode prev to be a nullptr
				nextNode->pPrev = nullptr;
				// Set the head to be the nextnode that was previously the previous of the head
				delete pHead;		// I dont think that this is necessary
				pHead = nextNode;
			}
		}

		// If the head is null then the ptail is also going to be set to null
		if (pHead == nullptr) pTail = nullptr;

		// Decrementing the size of the list
		size--;

		// If the