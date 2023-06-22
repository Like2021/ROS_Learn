#include "ros/ros.h"
#include "first_package/nums.h"


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 调用时动态传值，argc默认为1，即可执行文件的文件名
    if (argc != 3)
    {
        ROS_ERROR("请传递两个参数");
        return 1;
    }

    // 1.初始化节点
    ros::init(argc, argv, "AddInts_Client");
    // 2.创建句柄
    ros::NodeHandle nh;
    // 3.创建 客户端 对象
    ros::ServiceClient client = nh.serviceClient<first_package::nums>("AddInts");
    // 4.等待服务启动成功
    // 方式1
    // ros::service::waitForService("AddInts");
    // 方式2
    client.waitForExistence();
    // 5.组织请求数据
    first_package::nums nums;
    nums.request.num1 = atoi(argv[1]);
    nums.request.num2 = atoi(argv[2]);
    // 6.发送请求，返回bool值，标记是否成功
    bool flag = client.call(nums);
    // 7.处理响应
    if (flag)
    {
        ROS_INFO("请求正常处理，响应结果: %d", nums.response.sum);
    }
    else
    {
        ROS_ERROR("请求失败...");
        return 1;
    }
    
    return 0;
}