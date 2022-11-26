
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
