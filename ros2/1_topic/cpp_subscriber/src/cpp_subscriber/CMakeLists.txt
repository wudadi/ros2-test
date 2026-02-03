cmake_minimum_required(VERSION 3.8)
project(cpp_subscriber)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(cpp_listener src/cpp_subscriber.cpp)
ament_target_dependencies(cpp_listener rclcpp std_msgs)

install(TARGETS
  cpp_listener
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
