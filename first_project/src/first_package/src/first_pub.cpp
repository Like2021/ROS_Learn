#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    // 设置编码格式
    setlocale(LC_ALL, "");

    // 2.初始化ROS节点
    // 第三个参数是自定义节点名，需要唯一
    ros::init(argc, argv, "talker");

    // 3.实例化ROS句柄
    ros::NodeHandle nh;

    // 4.实例化一个Publisher对象
    // 第一个参数是自定义话题名
    // 第二个参数是队列中最大保存的最大消息数，超过的时候，先进的先销毁
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 10);

    // 5.定义需要发布的数据或逻辑
    // 初始化一个消息变量
    std_msgs::String msg;
    // 也可以直接
    // msg.data = "Hello!";

    // 消息前缀
    std::string msg_front = "Hello, 你好！";
    // 消息计数器
    int count = 0;

    // 发布逻辑
    ros::Rate r(1);

    // 只要节点没被关闭，循环发布
    while (ros::ok())
    {
        // 使用stringstream拼接字符串和编号
        // 先初始化对象
        std::stringstream ss;
        // 拼接
        ss << msg_front << count;
        msg.data = ss.str();

        // 发布消息
        pub.publish(msg);
        // 打印发布的消息
        ROS_INFO("发送的消息：%s", msg.data.c_str());

        // 根据前面频率自动休眠
        // 休眠时间 = 1 / 频率
        r.sleep();

        // 更新count
        count++;

        // 源代码说的是等待节点关闭，暂时没啥用
        ros::spinOnce();
    }

    return 0;
}