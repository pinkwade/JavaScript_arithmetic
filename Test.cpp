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
	a = Test.getLength();
	b = Test.retreive(1);
	cout << "Length: " << a << endl;
	cout << "Inserted number: " << b << endl;


	int arr[] = { 7, 3, 5, 9, 4 };
	OrderedList<int> olist;

	for (int k = 0; k < 5; k++)
	{
		olist.insert(arr[k]);
	}
	cout << "Ordered List: ";
	for (int k = 1; k <= 5; k++)
	{
		cout << olist.retreive(k);
	}
	cout << endl;
	system("PAUSE");
}