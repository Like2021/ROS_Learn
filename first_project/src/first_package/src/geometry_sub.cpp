#include "ros/ros.h"
#include "turtlesim/Pose.h"


void doPose(const turtlesim::Pose::ConstPtr& p)
{
    ROS_INFO("乌龟位姿信息:x=%.2f,y=%.2f,theta=%.2f,lv=%.2f,av=%.2f",
        p->x,p->y,p->theta,p->linear_velocity,p->angular_velocity
    );
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "sub_pose");
    // 创建句柄
    ros::NodeHandle nh;
    // 创建订阅者对象
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, doPose);
    
    ros::spin();

    return 0;
}