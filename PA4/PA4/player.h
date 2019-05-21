#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Position
{
	int x = 0;
	int y = 0;

};

class Player
{

public:
	//constructor
	Player(int newID = -1, int newX = -1, int newY = -1);

	//destructor
	~Player();

	//setters
	void setID(int newID);
	void setPosition(int newX, int newY);


	//getters
	int getID();
	Position getPosition();

private:
	int mID;
	Position mPosition;
};

//boolean operator for n <= m
//short circuit evaluation of [playerPositionN(x), playerPositionN(y)] <= [boardMax(x), boardMax(y)]
bool operator < (const Position &lhs, const Position &rhs);


#endif // !PLAYER_H