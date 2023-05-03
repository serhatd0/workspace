from launch import LaunchDescription 
from launch_ros.actions import Node 
from launch.actions import ExecuteProcess


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="udemy_ros2_pkg",
            executable="can_msgs",
            name="can_receiver_node",
        ),
        Node(
            package="udemy_ros2_pkg",
            executable="can_msgs",
            name="can_sender_node",
           
        ),
        ExecuteProcess(
            cmd=['ros2', 'topic', 'echo'],
            output='screen'
        )
    ])