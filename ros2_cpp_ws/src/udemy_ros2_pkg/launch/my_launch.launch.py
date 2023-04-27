import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    # Gazebo launch file path
    gazebo_launch_file = os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch')
    
    # Depth camera model and world file paths
    depth_camera_model_path = os.path.join(get_package_share_directory('gazebo_ros_depth_camera'), 'models', 'depth_camera', 'model.urdf')
    world_file_path = os.path.join(get_package_share_directory('gazebo_ros_depth_camera'), 'worlds', 'depth_camera_demo.world')

    return LaunchDescription([
        # Launch Gazebo
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([gazebo_launch_file]),
            launch_arguments={
                'world': world_file_path
            }.items()
        ),

        # Spawn depth camera model
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            name='spawn_depth_camera',
            arguments=['-entity', 'depth_camera', '-file', depth_camera_model_path]
        ),

        # Launch depth camera driver node
        Node(
            package='gazebo_ros_depth_camera',
            executable='gazebo_ros_depth_camera',
            name='gazebo_ros_depth_camera',
            remappings=[
                ('/camera/depth/image_raw', '/depth_camera/image_raw'),
                ('/camera/depth/camera_info', '/depth_camera/camera_info'),
            ]
        ),
    ])
