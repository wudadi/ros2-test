import rclpy
from rclpy.node import Node


class ParamNode(Node):

    def __init__(self):
        super().__init__('py_param_node')

        # 1️⃣ 声明参数
        self.declare_parameter('robot_name', 'robot1')
        self.declare_parameter('max_speed', 10)
        self.declare_parameter('enabled', True)

        # 2️⃣ 获取参数
        robot_name = self.get_parameter('robot_name').value
        max_speed = self.get_parameter('max_speed').value
        enabled = self.get_parameter('enabled').value

        self.get_logger().info(
            f'robot_name={robot_name}, '
            f'max_speed={max_speed}, '
            f'enabled={enabled}'
        )


def main():
    rclpy.init()
    rclpy.spin(ParamNode())
    rclpy.shutdown()