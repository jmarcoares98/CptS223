#ifndef BOARD_H
#define BOARD_H

#include "player.h"

class Board
{
public:
	//constructor with defaulr board size of 0
	Board(int boardSize = 0);

	//destructor function
	~Board();

	//implementing an Insert method that will allow to add a new player to the board.
	bool Insert(int playerID, int newX, int newY);

	//implementing a remove method that will allow to remove a player from the board.
	bool Remove(int playerID);

	//implementing a find method that is given a player ID and returns true if the player is found.
	bool Find(int playerID);

	//implement a MoveTo method that takes as input a player ID and a destination (x2,y2) cell position.
	bool MoveTo(int playerID, int desiredX, int desiredY);

	//implement a PrintById method that prints all player IDs along with their (x,y) positions.
	void PrintByID();

private:
	//using the map design for this one
	map<Position, int> mBoard;

	//map holding the playerID
	map<int, Player> mID;

	//boundaries of x and y
	int xBound;
	int yBound;
};

#endif // !BOARD_H