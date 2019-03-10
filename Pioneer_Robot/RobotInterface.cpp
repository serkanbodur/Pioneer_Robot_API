#include "RobotInterface.h"
/**
* \@File RobotInterface.cpp
* \@Author Serkan Bodur
* \@Date December 2017
*
*/
/**
* \brief RobotInterface default constructor 
*/
RobotInterface::RobotInterface()
{}
/**
* \brief Set the position info using position class(used aggregation)
* \param Range Sensor info
*/
void RobotInterface::setPosition(Position * pos)
{
	position = pos;
}
/**
* \brief Set the Range Sensor info using RangeSensor class(used aggregation)
* \param Range Sensor info
*/
void RobotInterface::setSensor(RangeSensor * sen)
{
	this->rangeSensor = sen;
}
/**
* \brief RobotInterface Destructor
*/
RobotInterface::~RobotInterface()
{
}
