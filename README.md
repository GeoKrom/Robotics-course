# Robotics-course

Semester project for course CSE/MYE031 - Robotics, Department of Computer Science and Engineering

This project consists of the design and implementation of the trajectory of [p2os](http://wiki.ros.org/p2os) robot using [ROS](http://wiki.ros.org/) and [gazebo simulator](http://gazebosim.org/). For the implementation of the trajectory, the cmd_vel topic was used, which belongs to the [geometry_msgs](http://wiki.ros.org/geometry_msgs) ([geometry_msgs/Twist](http://docs.ros.org/en/api/geometry_msgs/html/msg/Twist.html)) file.

# Trajectory Generation

The method that was used for the design of the trajectory are [cube polynomials](https://en.wikipedia.org/wiki/Cubic_function).

# Implementation

In order to move the robot into the space, there were created 5 trajectories, who are published in the cmd_vel topic of th geometry_msgs/Twist. 
This is happening after t_f seconds. For angular tranjectories, t_f is equaled to 10. For linear trajectories, t_f is equaled to 100.

# How to run

Open three terminals on your desktop.
In the first terminal run the command line 
```bash
roscore
```
in order to connect into the ROS core.

In the second terminal run the command line
```bach
roslaunch p2os_urdf pioneer3dx.gazebo.launch
```
in order to open gazebo simulator with p2os robot model.

In the third terminal run the command line
```bash
rosrun PathPlanning TrajectoryGen
```
so the robot can take the desired trajectories and move to the two point location inside the cartesian space.
