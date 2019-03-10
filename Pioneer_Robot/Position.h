#pragma once
class Position
{
	float x;
	float y;
	float th;
public:
	Position();
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
	float getTh();
	void setTh(float th);
	bool operator==(const Position& pos);
	~Position();
};

