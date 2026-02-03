#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_interfaces/action/count.hpp"

using Count = my_interfaces::action::Count;

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("cpp_count_client");
  auto client = rclcpp_action::create_client<Count>(node, "count");

  client->wait_for_action_server();

  Count::Goal goal;
  goal.target = 5;

  client->async_send_goal(goal);
  rclcpp::spin(node);
  rclcpp::shutdown();
}
