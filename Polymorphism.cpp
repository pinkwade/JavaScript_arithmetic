
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

	virtual void buyCollar(string name)
	{
		// set name of the collar
		catCollar.setName(name);
	}

	void getName()
	{
		cout << catCollar.getName() << endl;
	}

	virtual void speak() { cout << "Helloooo!!" << endl; }
};


int main()
{
	// Is this legal?
	Animal *animalPointer = new Cat;
	Cat *catPointer;

	catPointer = static_cast<Cat *>(animalPointer);
	catPointer->speak();

	// set the cats name
	catPointer->buyCollar("Cyriacs'Gay");
	catPointer->getName();

	// would using animalPointer give you the same outut? will it run?
	animalPointer->speak();
