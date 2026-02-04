import rclpy
from rclpy.node import Node

from tf2_ros import Buffer, TransformListener
from tf2_ros import TransformException


class TfListener(Node):

    def __init__(self):
        super().__init__('tf_listener')

        self.buffer = Buffer()
        self.listener = TransformListener(self.buffer, self)

        self.timer = self.create_timer(
            1.0,
            self.lookup
        )

    def lookup(self):
        try:
            t = self.buffer.lookup_transform(
                'base_link',
                'laser',
                rclpy.time.Time()
            )

            self.get_logger().info(
                f"laser in base_link: x={t.transform.translation.x:.2f}"
            )

        except TransformException as ex:
            self.get_logger().warn(str(ex))


def main():
    rclpy.init()
    node = TfListener()
    rclpy.spin(node)
    rclpy.shutdown()
