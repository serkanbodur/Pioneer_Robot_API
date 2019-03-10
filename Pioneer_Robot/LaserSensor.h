#pragma once
#include "RangeSensor.h"
//Eklenen Bir�ey Varsa buras� d�zeltilecek a��klama yok getRange diye bir�ey almam�z m�mk�n de�il
class LaserSensor : public RangeSensor
{
	float min;
	float max;
	string type;
public:
	LaserSensor();
	float getRange(int index);
	void setRange(float range[]);
	void updateSensor(float ranges[]);
	float getMax();
	float getMin();
	float operator[](int i);
	~LaserSensor();

};

