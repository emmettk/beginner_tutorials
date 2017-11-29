/* 
 * ROS Short Course @ WHOI: Assignment 1
 * Toy listener to experiment with ROS; goes with talker "talker.cpp"
 * Written by Emmett Krupczak
 * 29 Nov 2017
 * Code heavily borrowed from wiki.ros.org/ROS/Tutorials
 */

#include "ros/ros.h"
#include "std_msgs/String.h"

//This is what the listener provides when it receives a message

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Got a message! It said: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle node_handle;
  
  //Message buffer: 1000
  //Listen on channel "chatter", call chatterCallback
  ros::Subscriber sub = node_handle.subscribe("chatter", 1000, chatterCallback);
  ros::spin();
  return 0;
}
  
