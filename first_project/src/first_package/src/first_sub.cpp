#include "ros/ros.h"
#include "std_msgs/String.h"

// 创建回调函数
void doMsg(const std_msgs::String::ConstPtr& msg_p)
{
    ROS_INFO("我订阅了：%s", msg_p->data.c_str());
    // 指针参数，也可以是
    // ROS_INFO("我订阅了：%s", (*msg_p).data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化ROS节点，命名唯一
    ros::init(argc, argv, "listener");
    // 3.实例化ROS句柄
    ros::NodeHandle nh;

    // 4.实例化订阅者对象
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter", 10, doMsg);

    // 设置循环调用回调函数
    ros::spin();

    return 0;
}