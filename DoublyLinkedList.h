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
		Node *next, *curr = p