#pragma once
#include "Position.h"
#include "RangeSensor.h"
/**
* \@File RobotInterface.h
* \@Author Serkan Bodur
* \@Date December 2017
*
* \brief RobotInterface
* \brief This class is abstract class.
* \brief This class is Interface task for design simulator access and now It provides the interface to the Pioneer simulator.
* \brief But In the future, classes such as the PioneerRobotInterface class for different robot simulators will be added to 
* \brief provide an interface within them.
*/
class RobotInterface
{
	/**
	* \brief position attribute(from Position class using aggregation)
	*/
	Position *position;
	/**
	* \brief range sensor attribute(from RangeSensor class using aggregation)
	*/
	RangeSensor *rangeSensor;
public:

	//!An enum DIRECTION
	/*! This enum is used for robot directions */
	enum DIRECTION
	{
		left = -1,     /*!< If Robot wants to turn left,use direction left */
		forward = 0,   /*!< If Robot wants to go forward,use direction forward */
		right = 1      /*!< If Robot wants to turn right,use direction right */
	};
	/** 
	* \brief RobotInterface default constructor
	*/
	RobotInterface();
	/** 
	* \brief Setter function of position pointer info(used aggregation)
	* \param position info
	*/
	void setPosition(Position *pos);
	/**
	* \brief Setter function of Range sensor pointer info(used aggregation)
	* \param Range Sensor info
	*/
	void setSensor(RangeSensor *sen);
	/**
	* \brief Pure virtual function set sensor(used polymorphism)
	* \brief This function definition is given derivated class from this class
	*/
	virtual void update() = 0;
	/**
	* \brief Pure virtual function open (used polymorphism)
	* \brief This function definition is given derivated class from this class
	*/
	virtual bool open() = 0;
	/**
	* \brief Pure virtual function open(used polymorphism)
	* \brief This function definition is given derivated class from this class
	*/
	virtual bool close() = 0;
	/**
	* \brief Pure virtual function move(used polymorphism)
	* \brief This function definition is given derivated class from this class
	*/
	virtual void move(float speed) = 0;
	/**
	* \brief Pure virtual function turn(used polymorphism)
	* \brief This function definition is given derivated class from this class
	*/
	virtual void turn(DIRECTION dir) = 0;
	/**
	* \brief Pure virtual function stop(used polymorphism)
	* \brief This function definition is given derivated class from this class
	*/
	virtual void stop() = 0;
	/**
	* \brief RobotInterface Destructor
	*/
	~RobotInterface();

};

