#include "ros/ros.h"
#include "first_package/Person.h"


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 1.初始化ROS节点
    ros::init(argc, argv, "talker_person");

    // 2.创建ROS句柄
    ros::NodeHandle nh;

    // 3.创建发布者对象，第一个参数为话题名，第二个参数为message队列的大小
    ros::Publisher pub = nh.advertise<first_package::Person>("chatter_person", 1000);

    // ros::Duration(3).sleep();

    // 4.组织被发布的消息，编写发布逻辑并发布消息
    first_package::Person p;
    p.name = "Like";
    p.age = 23;
    p.height = 1.75;

    // 发布逻辑
    ros::Rate r(1);

    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        ROS_INFO("我叫: %s, 今年%d岁, 身高是%.2f米", p.name.c_str(), p.age, p.height);

        r.sleep();
        ros::spinOnce();
    }

    return 0;
}