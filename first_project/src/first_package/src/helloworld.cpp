#include "ros/ros.h"

int main(int argc, char *argv[])
{
    // 执行ros节点初始化
    ros::init(argc, argv, "hello");
    // 创建ros节点句柄(optional)
    ros::NodeHandle n;
    // 控制台输出
    ROS_INFO("Hello world!");

    return 0;
}