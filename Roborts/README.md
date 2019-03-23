# ROS Dependency:

sudo apt-get install ros-kinetic-ros-control ros-kinetic-ros-controllers \
	ros-kinetic-gazebo-ros-control

sudo apt install ros-kinetic-navigation-core


sudo sysctl fs.inotify.max_user_watches=65536


# Save Image :

1. roscd image_view

2. rosbag record -O <file-name> image:=<image_topic>

3. roslaunch roborts_navigation export.launch

# Reset World :

rosserviec call /gazebo/reset_world
