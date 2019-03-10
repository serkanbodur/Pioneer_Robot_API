#include "PioneerRobotInterface.h"
PioneerRobotInterface::PioneerRobotInterface()
{
	setRobot(this);
}

PioneerRobotInterface::PioneerRobotInterface(RangeSensor * sensor, Position * pos)
{
	setRobot(this);
	this->rangeSensor = sensor;
	this->position = pos;
}


void PioneerRobotInterface::update()
{
	position->setX(getX());
	position->setY(getY());
	position->setTh(getTh());
	setPosition(position);
	float ranges[16];
	float min, max;
	getSonarRange(ranges);
	rangeSensor->updateSensor(ranges);
	setSensor(rangeSensor);
}

bool PioneerRobotInterface::open()
{
	bool status = connect();
	if (status == 1)
		update();

	return status;
	
}

void PioneerRobotInterface::move(float speed)
{
	moveRobot(speed);
}

bool PioneerRobotInterface::close()
{
	return disconnect();
}

void PioneerRobotInterface::turn(RobotInterface::DIRECTION dir)
{
	switch (dir)
	{
	case RobotInterface::DIRECTION::left:
		turnRobot(PioneerRobotAPI::DIRECTION::left);
		break;
	case RobotInterface::DIRECTION::right:
		turnRobot(PioneerRobotAPI::DIRECTION::right);
		break;
	case RobotInterface::DIRECTION::forward:
		turnRobot(PioneerRobotAPI::DIRECTION::forward);
		break;
	default:
		break;
	}
}

void PioneerRobotInterface::stop()
{
	stopRobot();
}

void PioneerRobotInterface::updateRobot()
{
	position->setX(getX());
	position->setY(getY());
	position->setTh(getTh());
	setPosition(position);
	float ranges[16];
	float min, max;
	getSonarRange(ranges);
	rangeSensor->updateSensor(ranges);
	setSensor(rangeSensor);
}


PioneerRobotInterface::~PioneerRobotInterface()
{

}
