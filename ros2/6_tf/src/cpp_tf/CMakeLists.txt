cmake_minimum_required(VERSION 3.8)
project(cpp_tf)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(rclcpp REQUIRED)

# 3️⃣ TF 必须的包
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

# 4️⃣ TF 用到的消息类型
find_package(geometry_msgs REQUIRED)

# ========== TF Broadcaster ==========
add_executable(cpp_tf_broadcaster
  src/cpp_tf_pub.cpp
)

ament_target_dependencies(cpp_tf_broadcaster
  rclcpp
  tf2
  tf2_ros
  geometry_msgs
)

# ========== TF Listener ==========
add_executable(cpp_tf_listener
  src/cpp_tf_listener.cpp
)

ament_target_dependencies(cpp_tf_listener
  rclcpp
  tf2
  tf2_ros
  geometry_msgs
)

# 5️⃣ 安装可执行文件（ros2 run 必须）
install(TARGETS
  cpp_tf_broadcaster
  cpp_tf_listener
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
