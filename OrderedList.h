
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