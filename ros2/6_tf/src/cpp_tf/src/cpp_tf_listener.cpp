#include <memory>
#include <chrono>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "tf2/exceptions.h"

using namespace std::chrono_literals;

class TfListener : public rclcpp::Node
{
public:
  TfListener()
  : Node("tf_listener"),
    buffer_(this->get_clock())
  {
    listener_ = std::make_shared<tf2_ros::TransformListener>(buffer_);

    timer_ = this->create_wall_timer(
      1s,
      std::bind(&TfListener::lookup, this)
    );
  }

private:
  void lookup()
  {
    try {
      auto t = buffer_.lookupTransform(
        "base_link",
        "laser",
        tf2::TimePointZero
      );

      RCLCPP_INFO(
        this->get_logger(),
        "laser in base_link: x=%.2f",
        t.transform.translation.x
      );
    }
    catch (const tf2::TransformException & ex) {
      RCLCPP_WARN(this->get_logger(), "%s", ex.what());
    }
  }

  tf2_ros::Buffer buffer_;
  std::shared_ptr<tf2_ros::TransformListener> listener_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TfListener>());
  rclcpp::shutdown();
  return 0;
}
