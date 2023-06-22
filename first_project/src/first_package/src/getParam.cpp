/*
    参数服务器操作之查询_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param ----- 与 NodeHandle 类似
*/

#include "ros/ros.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "get_param");

    // param--------------------------------------------------------
    ROS_INFO("++++++++++++++++++++++++++++++++++++++");
    int res3 = ros::param::param("param_int", 20);  // 存在
    int res4 = ros::param::param("param_int2", 20);  // 不存在返回默认
    ROS_INFO("param获取的结果: %d, %d", res3, res4);

    // getParam函数
    // 先定义几个存储数据的变量
    int param_int_value;
    double param_double_value;
    bool param_bool_value;
    std::string param_string_value;
    std::vector<std::string> param_stus;
    std::map<std::string, std::string> param_friends;

    // 获取数据
    ros::param::get("param_int", param_int_value);
    ros::param::get("param_double",param_double_value);
    ros::param::get("param_bool",param_bool_value);
    ros::param::get("param_string",param_string_value);
    ros::param::get("param_vector",param_stus);
    ros::param::get("param_map",param_friends);

    ROS_INFO("getParam获取的数据: %d, %.2f, %s, %d",
    param_int_value, param_double_value, param_string_value.c_str(), param_bool_value);
    for (auto&& stu : param_stus)
    {
        ROS_INFO("stus元素: %s", stu.c_str());
    }
    for (auto&& f : param_friends)
    {
        ROS_INFO("map元素: %s = %s", f.first.c_str(), f.second.c_str());
    }

    // getParamCached()函数
    ros::param::getCached("param_int", param_int_value);
    ROS_INFO("通过缓存获取数据: %d", param_int_value);

    // getParamNames()
    std::vector<std::string> param_names2;
    ros::param::getParamNames(param_names2);
    for (auto&& name : param_names2)
    {
        ROS_INFO("解析到的名字name= %s", name.c_str());
    }
    ROS_INFO("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    // 判断数据是否存在
    ROS_INFO("存在 param_int 吗? %d", ros::param::has("param_int"));
    ROS_INFO("存在 param_inttt 吗? %d", ros::param::has("param_inttt"));

    // 搜索
    std::string key;
    ros::param::search("param_int", key);
    ROS_INFO("搜索: %s", key.c_str());

    return 0;
}