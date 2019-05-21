#include "player.h"

Player::Player(int newID, int newX, int newY)
{
	this->mID = newID;
	this->mPosition.x = newX;
	this->mPosition.y = newY;
}

Player::~Player()
{

}

void Player::setID(int newID)
{
	mID = newID;
}

void Player::setPosition(int newX, int newY)
{
	mPosition.x = newX;
	mPosition.y = newY;
}

int Player::getID()
{
	return this->mID;
}

Position Player::getPosition()
{
	return this->mPosition;
}


bool operator < (const Position &lhs, const Position &rhs)
{
	if ((lhs.x < rhs.x) || (lhs.x == rhs.x) && (lhs.y < rhs.y))
	{
		return true;
	}

	else
		return false;
}