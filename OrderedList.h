
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