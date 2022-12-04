
#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

template <class T>
class OrderedList
{
private:
	List<T> container;

public:

	OrderedList(int capacity = 500): container(capacity){}
	~OrderedList() {}

	bool isEmpty() const
	{
		return container.isEmpty();
	}

	int getLength() const
	{
		return container.getLength();
	}

	T remove(unsigned pos)
	{
		return container.remove(pos);
	}

	T retreive(unsigned pos) const
	{
		return container.retreive(pos);

	}

	int insert(T item)
	{
		int i;
		for (i = 1; i <= getLength(); i++)
		{
			//Less than sign makes the list in ascending order, change it to a greater than symbol to make it a list in descending order
			if (item < retreive(i))
			{
				break;
			}
		}
		container.insert(i, item);
		return i;
	}

	int find(T item)
	{
		int i;
		for (i = 1; i <= getLength(); i++)
		{
			if (item == retreive(i))
			{
				return i;
			}
		}
		return -1;


	}
};
