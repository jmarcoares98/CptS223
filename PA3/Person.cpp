#include "Person.h"

Person::Person(int newPosition)
{
	this->position = newPosition;
}

Person::~Person()
{

}

void Person::print()
{
	cout << this->position;
}

int Person::getPosition()
{
	return this->position;
}