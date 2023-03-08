#include <iostream>
#include <string>
#include "List.h"
#include "OrderedList.h"
using namespace std;

int main(char argc, char* argv[])
{
	int a, b;
	List<int> Test(10);
	Test.insert(1,20);
	a