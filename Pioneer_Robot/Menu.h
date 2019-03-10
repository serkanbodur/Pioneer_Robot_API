#pragma once
#include "RobotInterface.h"
#include "RobotControl.h"

#include <iostream>
class Menu
{
	Position *position;
	RangeSensor *sensor;
	RobotInterface *robotInterface;
	RobotControl *robotControl;
	boolean connectionStatus;
public:
	Menu();
	int controlInput(int menuRange,string input);
	void mainMenu();
	void connectionMenu();
	void motionMenu();
	void sensorMenu();
	float askDistance();
	int askSafeMoveSpeed();
	float askSpeed();
	float controlFloat(string input);
	int controlInteger(string input);
	~Menu();
};

