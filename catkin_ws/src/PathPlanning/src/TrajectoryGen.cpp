#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "rosgraph_msgs/Clock.h"
#include <stdio.h>
#include <math.h>
#include <sstream>

int main(int argc, char **argv){

	// Initialize nodes
	ros::init(argc, argv, "TrajectoryGen");
	ros::NodeHandle node;
	geometry_msgs::Twist msg;
	//Publisher for movement data
	ros::Publisher pub = node.advertise<geometry_msgs::Twist>("pioneer/cmd_vel", 10);

	double t;
    double rad_deg = M_PI/180;
	ros::Rate rate(10);
    
	while(ros::ok()){
		t = ros::Time::now().toSec();
		printf("%f\n", t);
		if (t < 10){
			msg.angular.z = (-0.159*pow(t, 2) + 1.59*t)*rad_deg;
			pub.publish(msg);	
		}
		else if( t >= 10 && t < 100){
			msg.angular.z = 0;
			msg.linear.x = (-0.000108*pow(t, 2) + 0.0054*t);
			pub.publish(msg);
		}
		else if(t >= 100 && t < 110){
			msg.linear.x = 0;
			msg.angular.z = (-0.669*pow(t, 2) + 6.99*t)*rad_deg;
			pub.publish(msg);
		}
		else if(t >= 110 && t < 210){
			msg.angular.z = 0;
			msg.linear.x = (-0.000096*pow(t, 2) + 0.0096*t);
			pub.publish(msg);
		}
		else if( t >= 210 && t < 220){
			msg.angular.x = 0;
			msg.angular.z = (-1.1004*pow(t, 2) + 11.004*t)*rad_deg;
			pub.publish(msg);
		}
		else{
			msg.angular.z = 0;
			msg.angular.x = 0;
			pub.publish(msg);
		}
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
