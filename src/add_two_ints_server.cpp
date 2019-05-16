#include "ros/ros.h"
#include "beginner_tutorials/Addtwoints.h"

bool add(beginner_tutorials::Addtwoints::Request &req,
        beginner_tutorials::Addtwoints::Response &res)
{
    res.sum = req.a +req.b;
    ROS_INFO("request: x = %1d, y = %1d",(long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%1d]",(long int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_inits_server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("add_two_ints",add);
    ROS_INFO("Ready to add two ints");
    
    ros::spin();
    return 0;
}