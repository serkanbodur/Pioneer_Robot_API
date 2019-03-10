#pragma once
#include "RangeSensor.h"
//Eklenen Birþey Varsa burasý düzeltilecek açýklama yok getRange diye birþey almamýz mümkün deðil
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

