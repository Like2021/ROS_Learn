#include "ros/ros.h"

int main(int argc, char* argv[])
{
    // 初始化ros节点
    ros::init(argc, argv, "Set_RGB");

    // 创建句柄
    // 注意：这里如果使用方式2去设置参数，别忘了创建句柄的时候加上功能包的名字
    ros::NodeHandle nh("turtlesim");
    // ros::NodeHandle nh;

    // 设置参数
    // 方式1,param
    // ros::param::set("/turtlesim/background_r", 0);
    // ros::param::set("/turtlesim/background_g", 0);   
    // ros::param::set("/turtlesim/background_b", 0);   

    // 方式2,setParam
    nh.setParam("background_r", 0);
    nh.setParam("background_g", 0);
    nh.setParam("background_b", 0);

    return 0;
}