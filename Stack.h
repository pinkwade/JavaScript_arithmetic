#pragma once
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
	List<T> container;

public:

	Stack(unsigned capacity): container(capacity) {}
	~Stack() {}

	bool isEmpty()const
	{
		return container.isEmpty();
	}

	bool isFull()const
	{
		return container.isFull();
	}

	unsigned size()const
	{
		return cont