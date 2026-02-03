import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class AddServer(Node):

    def __init__(self):
        super().__init__('py_add_server')
        self.srv = self.create_service(
            AddTwoInts, 'add_two_ints', self.callback)

    def callback(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info(
            f'Request: {request.a} + {request.b}')
        return response


def main():
    rclpy.init()
    rclpy.spin(AddServer())
    rclpy.shutdown()
