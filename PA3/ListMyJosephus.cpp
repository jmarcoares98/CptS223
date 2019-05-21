#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus()
{
	
}

ListMyJosephus::ListMyJosephus(int newN, int newM)
{
	init(newN, newM);
}

ListMyJosephus::~ListMyJosephus()
{

}

void ListMyJosephus::init(int newN, int newM)
{
	this->N = newN; 
	this->M = newM;
	this->size = N;

	for (int i = 0; i < N; i++)
	{
		Person newPerson = Person(i);
		//adds a newPerson and then pushes the newPerson to the back of the list for each loop
		this->circ.push_back(newPerson);

		//increment the size when a person is added;
		this->size++;
	}
}

void ListMyJosephus::clear()
{
	this->circ.clear();
	this->size = 0;
}

int ListMyJosephus::currentSize()
{
	cout << "Currently Playing: " << circ.size() << endl;

	return this->size;
}

bool ListMyJosephus::isEmpty()
{
	bool empty = false;

	if (this->circ.size() == 0)
	{
		empty = true;
	}

	return empty;
}

Person ListMyJosephus::eliminateNext()
{
	//passes around the potato to the players
	for (int i = 0; i < M; i++)
	{
		if (potato == circ.end())
		{
			potato = circ.begin();
		}
		potato++;
	}

	//this double checks if the potato is at the end
	if (potato == circ.end())
	{
		potato = circ.begin();
	}

	//determines who has the potato last and then eliminates them
	int eliminated = (*potato).getPosition();
	this->eliminatedPlayers.push_back(eliminated); //places the eliminated person on a elimination list for output later
	
	return *potato;
}

void ListMyJosephus::printAll()
{
	list<Person>::iterator print = circ.begin();

	cout << "Players: ";
	for (print = circ.begin(); print != circ.end(); print++)
	{
		cout << print->getPosition() << ", ";
	}
	cout << endl;
}

int ListMyJosephus::getWinner()
{
	return circ.begin()->getPosition();
}

void ListMyJosephus::printEliminated()
{
	if (!isEmpty())
	{
		cout << "Eimination Sequence: { ";

		for (auto it = eliminatedPlayers.begin(); it != eliminatedPlayers.end(); it++)
		{
			cout << *it << ", ";
		}

		cout << "}" << endl;

		cout << "Winner: " << getWinner() << endl;
	}

	eliminatedPlayers.clear();
}

void ListMyJosephus::wrapper()
{
	double duration = 0.0;
	double average = 0.0;

	potato = circ.begin();

	clock_t start = clock();

	cout << "Testing List..." << endl;
	//printAll();
	currentSize();
	while (circ.size() != 1)
	{
		eliminateNext();

		list<Person>::iterator check = potato;
		if (check == circ.end())
		{
			potato == circ.begin();
			circ.pop_back();
		}
		else
		{
			potato = circ.erase(potato);
		}

		size--;

		//printAll();
	}
	clock_t end = clock();

	duration = (end - start);
	duration = (duration / 1000);

	average = duration / (N - 1);

	printEliminated();
	circ.clear();

	cout << "Total Time: " << duration << " milliseconds" << endl;
	cout << "Average Time: " << average << " milliseconds" << endl;
	cout << "Test List Complete" << endl;
	//system("pause");
}