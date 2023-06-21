#include "ros/ros.h"
#include "first_package/Person.h"

// 创建回调函数
void doPerson(const first_package::Person::ConstPtr& p)
{
    ROS_INFO("我订阅了: 姓名是%s, 今年%d岁, 身高%.2f米", p->name.c_str(), p->age, p->height);

}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 1.初始化ROS节点
    ros::init(argc, argv, "listener_person");

    // 2.创建ROS句柄
    ros::NodeHandle nh;

    // 3.创建订阅者对象
    ros::Subscriber sub = nh.subscribe<first_package::Person>("chatter_person", 10, doPerson);

    ros::spin();
    
    return 0;
}