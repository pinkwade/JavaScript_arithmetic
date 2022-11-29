
#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class List
{
private:
	int size;
	int maxCapacity;
	T* container;

	inline int translate(unsigned pos)const
	{
		return pos - 1;
	}


public:

	List(int capacity = 500)
	{
		maxCapacity = capacity;
		container = new T[maxCapacity];
		size = 0;
	}
	~List() 
	{
		delete[] container;
	}

	bool isEmpty()const
	{
		return (size == 0);
	}

	bool isFull()const
	{
		return (size == maxCapacity);
	}

	unsigned getLength()const
	{
		return size;
	}

	void insert(unsigned pos, T item)
	{
		
		for (int i = size; i >= pos; i--)
		{
			container[translate(i+1)] = container[translate(i)];
		}
		container[translate(pos)] = item;
		size++;
	}

	T remove(unsigned pos)
	{
		T returnedValue = container[translate(pos)];
		for (int i = pos; i <= size; i++)
		{
			container[translate(i)] = container[i];
		}
		size--;
		return returnedValue;
	}

	T replace(unsigned pos, T item)
	{
		T returnedValue = container[translate(pos)];
		container[translate(pos)] = item;
		return returnedValue;
	}

	T retreive(unsigned pos)const
	{
		return container[translate(pos)];
	}

	void swap(unsigned i, unsigned j)
	{
		if (i == j) return;
		unsigned temp = container[translate(i)];
		container[translate(i)] = container[translate(j)];
		container[translate(j)] = temp;
	}
};
