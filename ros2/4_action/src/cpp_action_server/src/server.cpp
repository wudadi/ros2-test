#include <chrono>
#include <thread>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_interfaces/action/count.hpp"

using Count = my_interfaces::action::Count;

class CountServer : public rclcpp::Node
{
public:
  CountServer() : Node("cpp_count_server")
  {
    server_ = rclcpp_action::create_server<Count>(
      this,
      "count",
      std::bind(&CountServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
      std::bind(&CountServer::handle_cancel, this, std::placeholders::_1),
      std::bind(&CountServer::handle_accepted, this, std::placeholders::_1)
    );
  }

private:
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID &,
    std::shared_ptr<const Count::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Goal received: %d", goal->target);
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<Count>>)
  {
    RCLCPP_INFO(this->get_logger(), "Goal canceled");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<Count>> goal_handle)
  {
    std::thread{std::bind(&CountServer::execute, this, goal_handle)}.detach();
  }

  void execute(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<Count>> goal_handle)
  {
    auto feedback = std::make_shared<Count::Feedback>();
    auto result = std::make_shared<Count::Result>();

    for (int i = 1; i <= goal_handle->get_goal()->target; ++i) {
      if (goal_handle->is_canceling()) {
        result->final_count = i;
        goal_handle->canceled(result);
        return;
      }

      feedback->current = i;
      goal_handle->publish_feedback(feedback);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    result->final_count = goal_handle->get_goal()->target;
    goal_handle->succeed(result);
  }

  rclcpp_action::Server<Count>::SharedPtr server_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CountServer>());
  rclcpp::shutdown();
  return 0;
}
