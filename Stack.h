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

	Stack(unsigned capacity): contai