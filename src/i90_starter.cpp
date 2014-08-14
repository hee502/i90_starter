///////////////////////////////////////////////////////////////////////////////
//Source for i90_starter node to publish starting positions									 //
//v1.0 																																			 //
//Changelog:																																 //
//-First creation																									 //
//Huseyin Emre Erdem 																												 //
//14.08.2014 																																 //
///////////////////////////////////////////////////////////////////////////////

/*This node publishes the starting positions to trigger the calculation of the
first target position on i90_sensor_board node.*/

#include "ros/ros.h"
#include "pos.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher starterPub = n.advertise<i90_starter::pos>("i90_current_pos", 1);
//  ros::Rate loop_rate(10);

	i90_starter::pos currentPos;
	currentPos.fXPos = 0.00;
	currentPos.fYPos = 0.00;
	currentPos.fYawAngle = 45.00;
  ROS_INFO("Starting position: %0.2f\t%0.2f\t%0.2f", currentPos.fXPos, currentPos.fYPos, currentPos.fYawAngle);
	starterPub.publish(currentPos);

/*  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
*/

  return 0;
}

