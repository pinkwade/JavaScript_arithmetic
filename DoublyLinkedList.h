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
		Node(T item, Node *next = nullptr, Node *previous = nullptr) :data(item), pNext(