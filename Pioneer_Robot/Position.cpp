#include "Position.h"



Position::Position()
{
	this->x = 0;
	this->y = 0;
	this->th = 0;
}

float Position::getX()
{
	return this -> x;
}

void Position::setX(float x)
{
	this -> x = x;
}

float Position::getY()
{
	return this -> y;
}

void Position::setY(float y)
{
	this -> y = y;
}

float Position::getTh()
{
	return this -> th;
}

void Position::setTh(float th)
{
	this->th = th;
}

bool Position::operator==(const Position & pos)
{
	if (this -> getX() != pos.x)
		return false;
	if (this -> getY() != pos.y)
		return false;
	if (this -> getTh() != pos.th)
		return false;
	return true;
}


Position::~Position()
{
}
