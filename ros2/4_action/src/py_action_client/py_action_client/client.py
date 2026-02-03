import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from my_interfaces.action import Count


class CountClient(Node):

    def __init__(self):
        super().__init__('py_count_client')
        self.client = ActionClient(self, Count, 'count')
        self.client.wait_for_server()

        goal = Count.Goal()
        goal.target = 3

        self.client.send_goal_async(goal)


def main():
    rclpy.init()
    rclpy.spin(CountClient())
    rclpy.shutdown()
