#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Ros Init w/ Node Name Define
    ros::init(argc,argv, "talker");
    ros::NodeHandle nh;
    // topic name:chatter
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter",1);
    ros::Rate loop_rate(10); //Rate::sleep()

    int count = 0;
    // Ctrl-C or ros::shutdown() --> false, 
    // all ros::NodeHandles have been destoryed
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world" <<count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);
        
        ros::spinOnce(); // 현재 callback을 받지 않기 때문에 반드시 필요하지는 않음.
        
        loop_rate.sleep();
        count++;

    }

    return 0;
}   