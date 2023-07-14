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
    	time_now = ros::Time::now()
	while(ros::ok()){
		t = time_now.toSec();
		printf("Begin of the algorithm...\n");
		if (t < 10){
			printf("First Rotational Movement!\n");
			msg.angular.z = (-0.159*pow(t, 2) + 1.59*t)*rad_deg;
			pub.publish(msg);
		}
		else if( t >= 10 && t < 100){
			printf("First Linear Movement!\n");
			msg.angular.z = 0;
			msg.linear.x = (-0.000108*pow(t, 2) + 0.0054*t);
			pub.publish(msg);
		}
		else if(t >= 100 && t < 110){
			printf("Second Rotational Movement!\n");
			msg.linear.x = 0;
			msg.angular.z = (-0.669*pow(t, 2) + 6.99*t)*rad_deg;
			pub.publish(msg);
			printf("Reached middle point of path!\n");
			t = time_now.toSec();
		}
		else if(t >= 110 && t < 210){
			printf("Second Linear Movement!\n");
			msg.angular.z = 0;
			msg.linear.x = (-0.000096*pow(t, 2) + 0.0096*t);
			pub.publish(msg);
		}
		else if( t >= 210 && t < 220){
			printf("Third and Final Rotational Movement!\n");
			msg.angular.x = 0;
			msg.angular.z = (-1.1004*pow(t, 2) + 11.004*t)*rad_deg;
			pub.publish(msg);
			printf("Reached the desired point!\n");
		}
		else if(t >= 220){
			printf("End of the algorithm...\n");
			msg.angular.z = 0;
			msg.angular.x = 0;
			pub.publish(msg);
			printf("The Robot has Successfully followed the desired path!\n");
		}
		time_now =  ros::Time::now()
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
