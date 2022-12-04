
#include <iostream>
#include <string>

using namespace std;

// COLLAR CLASS
class Collar
{
private:
	string animalName;

public:
	void setName(string animalName)
	{
		this->animalName = animalName;
	}

	string getName()
	{
		return animalName;
	}
};