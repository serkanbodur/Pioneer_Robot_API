#include "RobotControl.h"



RobotControl::RobotControl()
{

}

RobotControl::RobotControl(RobotInterface * robotInterface, Position * pos, RangeSensor * sensor)
{
	this->sensor.push_back(sensor);
	this->robotInterface = robotInterface;
	this->position = pos;
	this->robotInterface->setPosition(pos);
	this->robotInterface->setSensor(this->sensor.at(0));
}
void RobotControl::safeMove(int speed)
{
	robotInterface->move(speed);
}


void RobotControl::turnLeft()
{
	robotInterface->turn(RobotInterface::DIRECTION::left);
}

void RobotControl::turnRight()
{
	robotInterface->turn(RobotInterface::DIRECTION::right);
}

void RobotControl::forward()
{
	robotInterface->turn(RobotInterface::DIRECTION::forward);
}

void RobotControl::print()
{
	cout << "MyPose is (" << position->getX() << "," << position->getY() << "," << position->getTh() << ")" << endl;
	cout << "Sonar ranges are [ ";
	for (int counter = 0; counter < sensor.size(); counter++)
	{
		for (int i = 0; i < 16; i++) {
			cout << sensor.at(counter)->getRange(i) << " ";
		}
		cout << "]" << endl;
	}
}

void RobotControl::moveDistance(float distance)
{
	robotInterface->move(distance);
	Sleep(1000);
	robotInterface->stop();
}

void RobotControl::closeWall()
{
	bool control_conflict = false;

	for (int sensCounter = 0; sensCounter < sensor.size(); sensCounter++)
	{
		robotInterface->update();
		if ((int)sensor.at(sensCounter)->getRange(3) < 100 || sensor.at(sensCounter)->getRange(4) < 100)
		{
			robotInterface->stop();
			control_conflict = true;
			break;
		}
	};

	while (control_conflict == false)
	{
		robotInterface->move(100);
		for (int sensCounter = 0; sensCounter < sensor.size(); sensCounter++)
		{
			if ((int)sensor.at(sensCounter)->getRange(3) < 300 || (int)sensor.at(sensCounter)->getRange(4) < 300)
			{
				robotInterface->stop();
				control_conflict = true;
				break;
			}
		}
	}
}

RobotControl::~RobotControl()
{
}
