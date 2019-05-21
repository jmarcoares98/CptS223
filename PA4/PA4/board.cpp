#include "board.h"

Board::Board(int boardSize)
{
	//this sets up the board and its limits
	this->xBound = boardSize - 1;
	this->yBound = boardSize - 1;
}

Board::~Board()
{

}

bool Board::Insert(int playerID, int newX, int newY)
{
	//preconditions for insertion:
	//(i) a player with the same ID should not already exist on the board
	//(ii) the specified insertion position on board should be currently unoccupied
	//(iii) to ensure the total number of players with this insertion should not exceed m.

	//true if all preconditions are met
	bool preconditionCheck = false;
	int check = 0;

	Player pos;

	pos.setPosition(newX, newY);

	//iterator for the checking the ID existing
	map<int, Player>::iterator iterator = mID.find(playerID);
	map<Position, int>::iterator posIterator = mBoard.find(pos.getPosition());

	if (!preconditionCheck)
	{
		//precondition i
		if (iterator != mID.end())
		{
			cout << "ERROR: PLAYER ID ALREADY EXISTS" << endl;
			system("pause");
			system("cls");

			check++;
		}

		//precondition ii
		if (posIterator != mBoard.end())
		{
			cout << "ERROR: POSITION OCCUPIED" << endl;
			system("pause");
			system("cls");

			check++;
		}


		//precondition iii
		if (mID.size() >= (xBound + 1))
		{
			cout << "ERROR: MAX PLAYERS!!" << endl;
			system("pause");
			system("cls");

			check++;
		}

		if (check == 0)
		{
			preconditionCheck = true;
		}
	}

	if (preconditionCheck == true)
	{
		//insert player and ID using pair stl
		mID.insert(pair<int, Player>(playerID, Player(playerID, newX, newY)));

		//insert  position in map
		mBoard.insert(pair<Position, int>(pos.getPosition(), playerID));

		cout << "Insert: (" << playerID << ", " <<newX << ", "<< newY << " )" << endl;
		system("pause");

		return true;
	}

	else
		return false;
}

bool Board::Remove(int playerID)
{
	map<int, Player>::iterator it = mID.find(playerID);

	//removing the player and removing the id 
	mBoard.erase(it->second.getPosition());
	mID.erase(it);

	return true;
}

bool Board::Find(int playerID)
{
	map<int, Player>::iterator it = mID.find(playerID);

	if (it == mID.end())
	{
		cout << "NOT IN LIST" << endl;
		system("pause");
		system("cls");

		return false;
	}

	else
		return true;
}

bool Board::MoveTo(int playerID, int newX, int newY)
{
	//First locate the player and move the player from its current position
	//Says (x1, y1) to the new position only if
	//	The new position  is in bounds
	//	The movement from x1 to x2 is always along the same row or same column or same diagonal direction

	bool preconditionCheck = false;
	int check = 0;

	Player pos;

	pos.setPosition(newX, newY);

	//iterator
	map<int, Player>::iterator it = mID.find(playerID);
	map<Position, int>::iterator posIt = mBoard.find(pos.getPosition());

	if (!preconditionCheck)
	{
		//check if the new position is in bounds
		if (xBound < newX || yBound < newY)
		{
			cout << "ERROR: NOT IN BOUNDS" << endl;
			system("pause");
			system("cls");

			check++;
		}

		//restrictions of movement
		if (abs(it->second.getPosition().x - newX) != abs(it->second.getPosition().y - newY)
			&& (it->second.getPosition().x != newX) && (it->second.getPosition().y != newY))
		{
			cout << "ERROR: NOT ALLOWED MOVESET" << endl;
			system("pause");
			system("cls");

			check++;
		}

		if (check == 0)
		{
			preconditionCheck = true;
		}
	}

	if (preconditionCheck == true)
	{
		cout << "Moving: " << playerID << endl;

		//checks if position is occupied
		if (posIt != mBoard.end())
		{
			//prompts user that the ID is being remove
			cout << posIt->second << " is removed" << endl;
			system("pause");
			system("cls");
			Remove(posIt->second);
		}

		it = mID.find(playerID);
		posIt = mBoard.find(it->second.getPosition());

		//removes the player and then inserts it into the new position
		mBoard.erase(posIt);
		mBoard.insert(pair<Position, int>(pos.getPosition(), playerID));

		it->second.setPosition(newX, newY);

		return true;
	}

	else
		return false;
}

void Board::PrintByID()
{
	//should not display any unoccupied positions

	//if the board is empty
	if (mID.size() == 0)
	{
		cout << "ERROR: EMPTY BOARD" << endl;
		system("pause");
		system("cls");
	}

	else
	{
		//iterator for for loop
		map<int, Player>::iterator it = mID.begin();

		for (; it != mID.end(); ++it)
		{
			cout << "ID: " << it->first << " Position: " << it->second.getPosition().x << ", " << it->second.getPosition().y << endl;
		}
	}

	system("pause");
	system("cls");
}