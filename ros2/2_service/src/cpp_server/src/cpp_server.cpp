#include "rclcpp/rclcpp.hpp"
//#include "example_interfaces/srv/add_two_ints.hpp"
#include "my_interfaces/srv/add_two_ints.hpp"


using AddTwoInts = my_interfaces::srv::AddTwoInts;

class AddServer : public rclcpp::Node
{
public:
  AddServer() : Node("cpp_add_server")
  {
    service_ = this->create_service<AddTwoInts>(
      "add_two_ints",
      std::bind(&AddServer::handle_request, this,
                std::placeholders::_1,
                std::placeholders::_2)
    );
  }

private:
  void handle_request(
    const std::shared_ptr<AddTwoInts::Request> request,
    std::shared_ptr<AddTwoInts::Response> response)
  {
    response->sum = request->a + request->b;
    RCLCPP_INFO(this->get_logger(),
      "Request: %ld + %ld", request->a, request->b);
  }

  rclcpp::Service<AddTwoInts>::SharedPtr service_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddServer>());
  rclcpp::shutdown();
  return 0;
}
