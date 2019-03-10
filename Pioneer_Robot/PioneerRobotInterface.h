#pragma once
#include "RobotInterface.h"
#include "PioneerRobotAPI.h"
#include "SonarSensor.h"
/**
* \@File PioneerRobotInterface.h
* \@Author Serkan Bodur
* \@Date December 2017
*
* \brief PioneerRobotInterface class.(Derivated class from RobotInterface class)
* \brief This class, using the functions of the Pioneer robot simulator,our design provides the interface.
* \brief Pure abstract functions in RobotInterface class,using the functions of the PioneerRobotAPI class.(using Inheritence)
*/
class PioneerRobotInterface : public RobotInterface , public PioneerRobotAPI
{
	/**
	* \brief range sensor attribute(from RangeSensor class using aggregation)
	*/
	RangeSensor *rangeSensor;
	/**
	* \brief position attribute(from Position class using aggregation)
	*/
	Position *position;
public:
	/**
	* \brief Default PioneerRobot constructor
	*/
	PioneerRobotInterface();
	/**
	* \brief PioneerRobotInterface constructor 
	* \param sensor info(used aggregation)
	* \param position info(used aggregation)
	*/
	PioneerRobotInterface(RangeSensor *sensor, Position *pos);
	/**
	* \brief This function is used to update location and sensor information.
	*/
	void update();
	/**
	* \brief This function opens the link with the robot simulator and makes the robota accessible.
	*/
	bool open();
	/**
	* \brief The progress of the robot is provided, at the speed given as parameter(mm/s).
	* \brief The robot goes backwards in "-" values.
	* \param speed information.
	*/
	void move(float speed);
	/**
	* \brief This function closes the link with the robot simulator
	*/
	bool close();
	/**
	* \brief This function Returns the robot as a parameter.
	* \brief When this function is creating,use inheritence 
	* \param direction information 
	*/
	void turn(RobotInterface::DIRECTION dir);
	/**
	* \brief This function close robot
	*/
	void stop();
	/**
	* \brief This function is used to  update robot's location and sensor information.
	*/
	void updateRobot();
	/**
	* \brief PioneerRobotInterface destructor
	*/
	~PioneerRobotInterface();
};

