# Example C++ Library Integration with ROS Packages

This project serves as an example that demonstrates how to create a C++ library and seamlessly link it to ROS (Robot Operating System) packages, enabling to leverage the rich functionalities provided by ROS in C++ projects.

## Prerequisites

Before running the examples, you need to install ROS. Follow these steps to install ROS on your system: [Installation/Ubuntu](http://wiki.ros.org/Installation/Ubuntu)

## Build & Install

```bash
git clone https://github.com/elkuno213/cpp-with-ros.git
cd cpp-with-ros
mkdir build && cd build
cmake ..
make
sudo make install
```

## Running Examples

```bash
# Run talker-listener example
roscore # Terminal 1
/opt/hvh/lib/localization_with_ros/listener_node # Terminal 2
/opt/hvh/lib/localization_with_ros/talker_node # Terminal 3

# Run ROS launch example
export ROS_PACKAGE_PATH=/opt/hvh/share:$ROS_PACKAGE_PATH
export CMAKE_PREFIX_PATH=/opt/hvh:$CMAKE_PREFIX_PATH
roslaunch localization_with_ros talker_listener.launch

# Run msgs example
/opt/hvh/bin/use_existing_msg
/opt/hvh/bin/use_custom_msg
/opt/hvh/bin/use_msgs.py

# Run srvs example
/opt/hvh/bin/use_existing_srv
/opt/hvh/bin/use_custom_srv
/opt/hvh/bin/use_srvs.py

# Run actions example
roscore # Terminal 1
/opt/hvh/bin/actionserver # Terminal 2
/opt/hvh/bin/actionclient # Terminal 3
```

## References

- [ROS Plain CMake](https://github.com/Tuebel/ros_plain_cmake)
- [ROS External Use](https://github.com/gerkey/ros1_external_use)
- [Catkin Conceptual Overview](http://wiki.ros.org/catkin/conceptual_overview)
- [Catkin CMakeLists.txt](http://wiki.ros.org/catkin/CMakeLists.txt)

## Contributions

Contributions to this example project are welcome. If you encounter any issues or have suggestions for improvements, please raise an issue on the GitHub repository.

## License

This example project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.

I hope this example project helps you understand and leverage the integration between C++ libraries and ROS packages effectively. Happy coding!
