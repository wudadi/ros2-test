from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    tf_broadcaster_node = Node(
        package='cpp_tf',
        executable='cpp_tf_broadcaster',
        name='tf_broadcaster',
        output='screen'
    )

    tf_listener_node = Node(
        package='cpp_tf',
        executable='cpp_tf_listener',
        name='tf_listener',
        output='screen'
    )

    return LaunchDescription([
        tf_broadcaster_node,
        tf_listener_node
    ])
