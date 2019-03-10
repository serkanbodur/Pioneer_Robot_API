#pragma once
#include "Aria/Aria.h"
#include <iostream>

class PioneerRobotAPI {
	ArPose pose;
	ArRobot *robot;
	ArSonarDevice *sonar;
	ArRobotConnector *robotConnector;
	ArFunctorC<PioneerRobotAPI>  *pCB;
	PioneerRobotAPI *robotAPI;

	void updateCB(void);
public:
	enum DIRECTION {
		left = -1,
		forward = 0,
		right = 1
	};

	PioneerRobotAPI();
	~PioneerRobotAPI();

	/** Used to connect to the robot. Ths function should be called before others.
	* @return true if the connection is success, otherwise false
	*/
	bool connect();
	/** Used to disconnect to the robot. Ths function should be called before quiting from program.
	* @return true if the connection is success, otherwise false
	*/
	bool disconnect();
	/** moves the robot at the given speed.
	* @param speed required motion speed for the robot (millimeter/seconds)
	*/
	void moveRobot(float speed);
	/** stops the robot.
	*/
	void stopRobot();
	/** Rotates the robot to the given direction.
	* @param dir required direction to turn the robot (left, right, forward)
	*/
	void turnRobot(DIRECTION dir);
	/** Gets the sonar range values as an array with size of 16.
	* @param ranges current sonar range readings (the range values are in millimeter)
	*/
	void getSonarRange(float ranges[]) const;
	/** Gets the x position of the robot.
	* @return the x positon of the robot(the values are in millimeter)
	*/
	float getX() const;
	/** Gets the y position of the robot.
	* @return the y positon of the robot(the values are in millimeter)
	*/
	float getY() const;
	/** Gets the orientation angle of the robot.
	* @return the orientation angle of the robot (the values are in degrees)
	*/
	float getTh() const;
	/** Sets the positon of the robot.
	* @param x the required x position of the robot (the values are in millimeters)
	* @param y the required y position of the robot (the values are in millimeters)
	* @param th the required orientation angle of the robot (the values are in degrees)
	*/
	void setPose(float x, float y, float th);
	/** Gets the laser range values as a min and max values.
	* @param min reference for the min value of the laser sensor (the range values are in millimeter)
	* @param max reference for the max value of the laser sensor (the range values are in millimeter)
	*/
	void getLaserRange(float &min, float &max) const;

	/** This function is automatically called every one seconds. If you need, you can override this function in a your class by inheritance.
	* Look at the test program to learn how to use.
	*/
	virtual void updateRobot() {}
	/** This function is called to use your updateRobot() function
	* @param robotapi assign "this" pointer in your inheriting class to be able to use updateRobot()
	*/
	void setRobot(PioneerRobotAPI *robotapi);
};

