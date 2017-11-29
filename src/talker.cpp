/* 
 * ROS Short Course @ WHOI: Assignment 1
 * Toy talker to experiment with ROS; goes with listener "listener.cpp"
 * Written by Emmett Krupczak
 * 29 Nov 2017
 * Code heavily borrowed from wiki.ros.org/ROS/Tutorials and Louis Whitcomb
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

// Create a pointer to a publisher for later use
ros::Publisher chatter_pub;

//Hz for calls
static int calls_per_sec = 10;

// This function publishes the message
void TimerCallback(const ros::TimerEvent&)
{
 static int count = 0;
 std_msgs::String msg;

 std::stringstream ss;
 count++;
 float elapsed_time = (float)count / (float)calls_per_sec;
ss << "Hi Emmett! The count is " << count <<" and the elapsed time is " << elapsed_time << " sec";
 msg.data = ss.str();

 ROS_INFO("%s", msg.data.c_str());
 chatter_pub.publish(msg);
 }



int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle node_handle;

//Message buffer: 1000
//Publish on channel "chatter"
  chatter_pub = node_handle.advertise<std_msgs::String>("chatter", 1000);
//Create a timer with the desired callback frequency, call TimerCallback
  ros::Timer timer = node_handle.createTimer(ros::Duration(1.0/(float)calls_per_sec), TimerCallback);
  ros::spin();
  return 0;
 }
