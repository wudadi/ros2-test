import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class AddClient(Node):

    def __init__(self):
        super().__init__('py_add_client')
        self.client = self.create_client(AddTwoInts, 'add_two_ints')

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service...')

        request = AddTwoInts.Request()
        request.a = 5
        request.b = 6

        future = self.client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        self.get_logger().info(
            f'Result = {future.result().sum}')


def main():
    rclpy.init()
    AddClient()
    rclpy.shutdown()
