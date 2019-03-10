#include "SonarSensor.h"

SonarSensor::SonarSensor()
{
	this->type = "Sonar L131 Sensor";
	setType("Sonar L131 Sensor");
}

float SonarSensor::getRange(int index)
{
	return this -> ranges[index];
}

void SonarSensor::setRange(float range[])
{
	for (int i = 0; i < 16; i++)
	{
		this -> ranges[i] = range[i];
	}
}

float SonarSensor::getMax()
{
	
	float maximumValue = this->ranges[0];
	for (int i = 1; i < 16; i++)
	{
		if (maximumValue < this->ranges[i])
		{
			maximumValue = this->ranges[i];
		}
	}
	return maximumValue;
}

float SonarSensor::getMin()
{
	float minimumValue = this->ranges[0];
	for (int i = 1; i < 16; i++)
	{
		if (minimumValue > this->ranges[i])
		{
			minimumValue = this->ranges[i];
		}
	}
	return minimumValue;
}

void SonarSensor::updateSensor(float ranges[])
{
	for (int i = 0; i < 16; i++)
	{
		this->ranges[i] = ranges[i];
	}
}

float SonarSensor::operator[](int i)
{
	return this->ranges[i];
}



SonarSensor::~SonarSensor()
{
}
