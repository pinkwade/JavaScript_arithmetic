
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

// ANIMAL CLASS - pure virtual, abstract
class Animal
{
public:
	Animal() {}
	virtual ~Animal() { cout << "Theres no more animal;" << endl; }
	virtual void speak() = 0;
	virtual void buyCollar(string name) = 0;
};

// CAT CLASS - derived from Animal class
class Cat : public Animal
{
private:
	Collar catCollar;

public:
	Cat() {}
	~Cat() { cout << "Cat has died" << endl; }