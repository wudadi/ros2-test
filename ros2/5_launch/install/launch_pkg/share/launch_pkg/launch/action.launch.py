from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([

        # Action Server
        Node(
            package='cpp_action_server',
            executable='cpp_action_server',
            name='count_server',
            output='screen'
        ),

        # Action Client
        Node(
            package='cpp_action_client',
            executable='cpp_action_client',
            name='count_client',
            output='screen'
        )
    ])
