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

		// If the doubly linked list is empty then set head and tail to empty
		if (getSize() == 0) {
			pHead = nullptr;
			pTail = nullptr;
		}

		// Return the data value that was in the destroyed node (destroyed head)
		return returnData;
	}

	// REMOVE TAIL 
	T removeTail() {
		T returnData = pTail->data;

		// If there is something in pTail do this
		if (pTail != NULL)
		{
			Node *previousToTail = pTail->pPrev;	// Get what comes before the tail
			if (previousToTail != NULL)				// If what comes before the tail is not null
			{										// Set the previous of that to null since it is the new tail
				previousToTail->pNext = nullptr;	// Delete the old tail and set the previous tail to be the new tail

				delete pTail;
				pTail = previousToTail;
			}
			// If there is nothing in pTail do the else
			else
			{
				pHead = nullptr;
			}
		}

		// Decrement size
		size--;

		// Set everything to null 
		if (getSize() == 0)
		{
			pHead = nullptr;
			pTail = nullptr;
		}

		return returnData;
	}

	// REMOVE
	T remove(unsigned pos) {
		// Basic checks for beginning and end cases
		if (pos == 1) return removeHead();
		if (pos == size) return removeTail();

		// Getting the previous node of the current node, to the left of it
		Node * prev = getNode(pos - 1);
		// Getting the next node of the current node, to the right of it
		Node * next = getNode(pos + 1);
		// Getting the current node. the middle node that we want to remove
		Node * curr = getNode(pos);

		T ret = curr->data;		// Get the data that we will return

		// Set the previous nodes next pointer to point to the next node of the current node we deleted
		prev->pNext = next;

		// Set the next nodes previous pointer to point to the prevoius node of the current node we deleted
		next->pPrev = prev;

		// Decrement
		size--;

		delete curr;
		return ret;
	}

	// REPLACE
	T replace(unsigned pos, T item) {
		// Get the current node
		Node *currentNode = getNode(pos);

		// Return the current data value
		T returnData = currentNode->data;

		currentNode->data = item;

		return returnData;
	}

	// EQUALITY FUNCTOR
	class DFLT_EQ
	{
	public:
		static bool compare(T a, T b)		// Compares the values
		{
			return a == b;
		}
	};

	// FIND 
	template <class EQ = DFLT_EQ>
	int find(T item) {
		Node *curr = pHead;
		int pos = 1;

		// Looping through the lists node data and comparing that to the value we would like to find, we return the position if we find it
		while (curr != nullptr) {
			if (EQ::compare(item, curr->data)) return pos;
			curr = curr->pNext;
			pos++;
		}
		return -1;
	}

	// ITERATOR CLASS
	class Iterator {
	private:
		Node *m_ptr;
	public:
		Iterator(Node *ptr) :m_ptr(ptr) {}
		void operator++() { m_ptr = m_ptr->pNext; }
		void operator--()
		{
			m_ptr = m_ptr->pPrev;
		}
		bool operator!=(const Iterator &other) { return (m_ptr == other.m_ptr); }
		T getValue() { return m_ptr->data; }
		void setValue(T item) { m_ptr->data = item; }
	};

	// LAST
	Iterator last()
	{
		return Iterator(pTail);
	}

	// BEGIN
	Iterator begin()
	{
		return Iterator(pHead);
	}

	// END
	Iterator end()
	{
		return Iterator(nullptr);
	}





	//COPIED VALIDATION SHIT
	bool validate(unsigned count, ...) {
		if (count != size) {
			cout << "validate FAIL:Size does not match!" << count << ":" << size << endl;
			return false;
		}
		//if empty list, verify list variables (head/tail/size)
		if (size == 0 || pHead == nullptr || pTail == nullptr) {
			if (size != 0 || pHead != nullptr || pTail != nullptr) {
				cout << "validate FAIL:List empty/not empty mismatch!" << endl;
				cout << "  Size:" << size << endl;
				cout << "  pHead==nullptr:" << (pHead == nullptr) << endl;
				cout << "  pTail==nullptr:" << (pTail == nullptr) << endl;
				return false;
			}
		}
		else {
			//Not an empty list, verify pHead->pPrev != nullptr and pTail->pNext != nullptr
			if (pHead->pPrev != nullptr) {
				cout << "validate FAIL:pHead->pPrev != nullptr!" << endl;
				return false;
			}
			if (pTail->pNext != nullptr) {
				cout << "validate FAIL:pTail->pNext != nullptr!" << endl;
				return false;
			}
		}
		//copy argument list to array
		T *arr = new T[count];
		va_list arguments;
		va_start(arguments, count);
		for (unsigned x = 0; x < count; x++)
			arr[x] = va_arg(arguments, T);
		va_end(arguments);

		Node *curr;
		//validate next Node pointers
		curr = pHead;
		for (unsigned pos = 1; pos <= size; pos++) {
			if (curr == nullptr) {
				cout << "validate FAIL:Forward traversal-Node " << pos << " is a nullptr!" << endl;
				delete[] arr;
				return false;
			}
			if (curr->data != arr[pos - 1]) {
				cout << "validate FAIL:Forward node data " << curr->data << " does not match arr data " << arr[pos - 1] << endl;
				delete[] arr;
				return false;
			}
			curr = curr->pNext;
		}
		//validate prev Node pointers
		curr = pTail;
		for (unsigned pos = size; pos >= 1; pos--) {
			if (curr == nullptr) {
				cout << "validate FAIL:Backward traversal-Node " << pos << " is a nullptr!" << endl;
				delete[] arr;
				return false;
			}
			if (curr->data != arr[pos - 1]) {
				cout << "validate FAIL:Backward node data " << curr->data << " does not match arr data " << arr[pos - 1] << endl;
				delete[] arr;
				return false;
			}
			curr = curr->pPrev;
		}
		delete[] arr;
		return true;
	}


};
