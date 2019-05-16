#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::StringConstPtr& msg)
{
    ROS_INFO("I heard: [%s]",msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc,argv, "Listener");
    ros:: NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatter",1, chatterCallback);
    ros::spin();
    return 0;
}