from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

from ament_index_python.packages import get_package_share_directory
from os.path import join as Path

from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch.actions import SetEnvironmentVariable

from launch.actions import RegisterEventHandler,EmitEvent
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown

ignition_ros_package_path = get_package_share_directory("ros_ign_gazebo")
udemy_ros2_pkg_path= get_package_share_directory("udemy_ros2_pkg")
simulation_world_file_path = Path(udemy_ros2_pkg_path,"worlds","project_world.sdf")
simulation_models_path=Path(udemy_ros2_pkg_path,"models")



## 
# simulation= IncludeLaunchDescription(
#             PythonLaunchDescriptionSource(
#             launch_file_path=Path(ignition_ros_package_path,"launch","ign_gazebo.launch.py")
#             ),
#             launch_arguments={"ign_args":"-r " + simulation_world_file_path}.items()
#         )

simulation = ExecuteProcess(
    cmd=['ign','gazebo','-r',simulation_world_file_path],
    output='screen'
)

def generate_launch_description():
    return LaunchDescription([
        SetEnvironmentVariable(
                name="IGN_GAZEBO_RESOURCE_PATH",
                value=simulation_models_path
        ),
        simulation,
        Node(
            package="ros_ign_bridge",
            executable="parameter_bridge",
            arguments=[
                "/model/wheeled_model/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist"
            ],
            #ros_arguments=["model/wheeled_model/cmd_vel:=/cmd_vel"],  Remapping topic in terminal
            remappings=[("model/wheeled_model/cmd_vel","/cmd_vel")],
            output="screen"
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=simulation,
                on_exit=[EmitEvent(event=Shutdown())]
            )
        )
        
    ])