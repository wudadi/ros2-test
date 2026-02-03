#include "rclcpp/rclcpp.hpp"

class ParamNode : public rclcpp::Node
{
public:
  ParamNode() : Node("cpp_param_node")
  {
    // 1️⃣ 声明参数（必须）
    this->declare_parameter<std::string>("robot_name", "robot1");
    this->declare_parameter<int>("max_speed", 10);
    this->declare_parameter<bool>("enabled", true);

    // 2️⃣ 获取参数
    robot_name_ = this->get_parameter("robot_name").as_string();
    max_speed_  = this->get_parameter("max_speed").as_int();
    enabled_    = this->get_parameter("enabled").as_bool();

    RCLCPP_INFO(this->get_logger(),
      "robot_name=%s, max_speed=%d, enabled=%d",
      robot_name_.c_str(), max_speed_, enabled_);
  }

private:
  std::string robot_name_;
  int max_speed_;
  bool enabled_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParamNode>());
  rclcpp::shutdown();
  return 0;
}
