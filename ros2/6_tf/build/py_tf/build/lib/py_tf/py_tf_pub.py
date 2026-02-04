import rclpy
from rclpy.node import Node

from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster


class TfBroadcaster(Node):

    def __init__(self):
        super().__init__('tf_broadcaster')

        self.broadcaster = TransformBroadcaster(self)

        self.timer = self.create_timer(
            0.1,  # 100ms
            self.publish_tf
        )

    def publish_tf(self):
        t = TransformStamped()

        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'base_link'
        t.child_frame_id = 'laser'

        t.transform.translation.x = 1.0
        t.transform.translation.y = 0.0
        t.transform.translation.z = 0.0

        t.transform.rotation.w = 1.0

        self.broadcaster.sendTransform(t)


def main():
    rclpy.init()
    node = TfBroadcaster()
    rclpy.spin(node)
    rclpy.shutdown()
