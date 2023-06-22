// 1.包含头文件
#include "ros/ros.h"
#include "first_package/nums.h"

// bool 返回值用于标志是否处理成功
bool doReq(first_package::nums::Request& req, first_package::nums::Response& resp)
{
    int num1 = req.num1;
    int num2 = req.num2;

    ROS_INFO("服务器接收到的请求数据为:num1 = %d, num2 = %d",num1, num2);

    // 逻辑处理
    if (num1 < 0 || num2 < 0)
    {
        ROS_ERROR("提交的数据异常: 数据不可以为负数");
        return false;
    }

    // 如果没有ERROR，那就相加并将结果赋值给resp
    resp.sum = num1 + num2;

    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"AddInts_Server");
    // 3.创建 ROS 句柄
    ros::NodeHandle nh;
    // 4.创建 服务 对象
    ros::ServiceServer server = nh.advertiseService("AddInts", doReq);
    ROS_INFO("服务已经启动....");
    //     5.回调函数处理请求并产生响应
    //     6.由于请求有多个，需要调用 ros::spin()
    ros::spin();
    return 0;
}