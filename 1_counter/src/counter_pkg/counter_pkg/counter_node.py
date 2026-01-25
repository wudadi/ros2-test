import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class CounterNode(Node):
    def __init__(self):
        super().__init__('counter_node')

        self.declare_parameter('start', 0)
        self.declare_parameter('step', 1)

        self.start = self.get_parameter('start').value
        self.step = self.get_parameter('step').value

        self.count = self.start

        self.publisher_ = self.create_publisher(Int32, 'counter', 10)
        self.get_logger().info(f'counter start! start = {self.start}, step = {self.step}')
        self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        msg = Int32()
        msg.data = self.count
        self.publisher_.publish(msg)
        self.get_logger().info(f'count is {self.count}')
        self.count += self.step

def main():
    rclpy.init()
    node = CounterNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()