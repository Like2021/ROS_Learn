#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 初始化ROS节点
    ros::init(argc, argv, "control");

    // 创建ROS句柄
    ros::NodeHandle nh;

    // 创建发布者对象，第一个参数为话题名
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);

    // 组织需要发送的消息
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 2.0;

    // 设置发送频率
    ros::Rate r(10);
    // 循环发送
    while (ros::ok())
    {
        pub.publish(msg);

        ros::spinOnce();
    }

    return 0;
}