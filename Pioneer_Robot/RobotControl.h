#pragma once
#include <vector>
#include <math.h>
#include "RobotInterface.h"
#include "RangeSensor.h"
#include "SonarSensor.h"
#include "Position.h"
#include "PioneerRobotInterface.h"
using namespace std;
class RobotControl 
{
	vector<RangeSensor *> sensor;
	Position *position;
	RobotInterface *robotInterface;
public:
	RobotControl();
	RobotControl(RobotInterface *robotInterface,Position *pos,RangeSensor * sensor);
	void safeMove(int speed);
	void turnLeft();
	void turnRight();
	void forward();
	void print();
	void moveDistance(float distance);
	void closeWall();
	~RobotControl();
};

