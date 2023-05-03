import os

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='can_msgs',
            node_executable='can_receiver_node',
            output='screen',
            remappings=[
                ('can_rx', 'vcan0')
            ]
        ),
        Node(
            package='can_msgs',
            node_executable='can_transmitter_node',
            output='screen',
            remappings=[
                ('can_tx', 'vcan0')
            ],
            parameters=[
                {"frame_id": 101, "data": [1, 2, 3, 4, 5, 6, 7, 8]}
            ]
        ),
    ])
