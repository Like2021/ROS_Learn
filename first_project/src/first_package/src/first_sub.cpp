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
}