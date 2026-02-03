#include "rclcpp/rclcpp.hpp"
//#include "example_interfaces/srv/add_two_ints.hpp"
#include "my_interfaces/srv/add_two_ints.hpp"


using AddTwoInts = my_interfaces::srv::AddTwoInts;

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("cpp_add_client");
  auto client = node->create_client<AddTwoInts>("add_two_ints");

  while (!client->wait_for_service(std::chrono::seconds(1))) {
    RCLCPP_INFO(node->get_logger(), "Waiting for service...");
  }

  auto request = std::make_shared<AddTwoInts::Request>();
  request->a = 3;
  request->b = 4;

  auto future = client->async_send_request(request);
  rclcpp::spin_until_future_complete(node, future);

  RCLCPP_INFO(node->get_logger(),
    "Result = %ld", future.get()->sum);

  rclcpp::shutdown();
  return 0;
}
