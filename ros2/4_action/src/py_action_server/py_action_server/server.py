import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from my_interfaces.action import Count


class CountServer(Node):

    def __init__(self):
        super().__init__('py_count_server')
        self.server = ActionServer(
            self, Count, 'count', self.execute)

    def execute(self, goal_handle):
        self.get_logger().info('Executing goal')

        feedback = Count.Feedback()
        for i in range(1, goal_handle.request.target + 1):
            feedback.current = i
            goal_handle.publish_feedback(feedback)
            time.sleep(1)

        goal_handle.succeed()
        result = Count.Result()
        result.final_count = goal_handle.request.target
        return result


def main():
    rclpy.init()
    rclpy.spin(CountServer())
    rclpy.shutdown()
