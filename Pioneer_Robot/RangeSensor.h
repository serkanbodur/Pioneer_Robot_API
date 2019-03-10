#pragma once
#include <string>
using namespace std;
//Generalization Specialization ilkelerine göre LaserSensor Sonar Sensor iliþkilerini alýr
class RangeSensor
{
	string type;
public:
	RangeSensor();
	virtual void updateSensor(float ranges[]) = 0;
	virtual float getMin() = 0;
	virtual float getMax() = 0;
	virtual float getRange(int index) = 0;
	void setType(string type);
	string getType();
	virtual float operator[](int i) = 0;
	~RangeSensor();
};

