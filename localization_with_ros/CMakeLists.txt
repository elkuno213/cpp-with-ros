# ──────────────────────────────────────────────────────────────────────────── #
# Project #

cmake_minimum_required(VERSION 3.15.0)
project(localization_with_ros VERSION 0.1)
include("${CMAKE_SOURCE_DIR}/cmake/ros_install_directories.cmake")




# ──────────────────────────────────────────────────────────────────────────── #
# Add custom messages, services, actions

# Add messages
add_message_files(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/msgs
  FILES     Foo.msg Bar.msg
)

# Add services
add_service_files(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/srvs
  FILES     Bat.srv Baz.srv
)

# Add actions
# Note: Be careful that the argument DIRECTORY of add_action_files() is
#       relative one to ${CMAKE_CURRENT_SOURCE_DIR}
add_action_files(
  DIRECTORY actions
  # DIRECTORY .
  FILES DoDishes.action
)

# Generates messages, services, actions based on dependencies
generate_messages(
  DEPENDENCIES geometry_msgs map_msgs sensor_msgs actionlib_msgs
)




# ──────────────────────────────────────────────────────────────────────────── #
# Add executables #

add_subdirectory(localization_with_ros)
add_subdirectory(examples)




# ──────────────────────────────────────────────────────────────────────────── #
# Installation #

# Install Python scripts
# Remember to export python path from this package before running python file
# export PYTHONPATH=/opt/hvh/lib/python3/dist-packages:$PYTHONPATH
install(
  PROGRAMS    ${CMAKE_CURRENT_SOURCE_DIR}/scripts/use_msgs.py
              ${CMAKE_CURRENT_SOURCE_DIR}/scripts/use_srvs.py
  DESTINATION ${ROS_INSTALL_BINDIR}
)

# Install launch files
# Remember to export the ROS/CMake paths of this package before launching
# export ROS_PACKAGE_PATH=/tmp/install/share:$ROS_PACKAGE_PATH
# export CMAKE_PREFIX_PATH=/tmp/install:$CMAKE_PREFIX_PATH
install(
  FILES       ${CMAKE_CURRENT_SOURCE_DIR}/launch/talker_listener.launch
  DESTINATION ${ROS_INSTALL_LAUNCHDIR}
)

# Install package.xml, which is necessary to be treated as a ROS package
install(
  FILES       ${CMAKE_CURRENT_SOURCE_DIR}/package.xml
  DESTINATION ${ROS_INSTALL_SHAREDIR}
)

# Install .catkin file so that rosrun/roslaunch can look for executables
IF(EXISTS "${CMAKE_INSTALL_PREFIX}/.catkin")
  MESSAGE(STATUS "${CMAKE_INSTALL_PREFIX}/.catkin already exists")
ELSE()
  file(WRITE "${CMAKE_INSTALL_PREFIX}/.catkin")
ENDIF()

# Export targets for build tree / in workspace
export(
  EXPORT    ${PROJECT_NAME}Targets
  FILE      ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
  NAMESPACE hvh::
)

# Install targets
install(
  EXPORT      ${PROJECT_NAME}Targets
  FILE        ${PROJECT_NAME}Targets.cmake
  NAMESPACE   hvh::
  DESTINATION ${ROS_INSTALL_CMAKEDIR}
)

# Install the package configuration files
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  DESTINATION ${ROS_INSTALL_CMAKEDIR}
)

# CMake write package configuration file
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  VERSION       ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

# CMake generate package configuration file
set(INCLUDE_INSTALL_DIR ${ROS_INSTALL_INCLUDEDIR})
configure_package_config_file(
  ${CMAKE_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${ROS_INSTALL_CMAKEDIR}
  PATH_VARS INCLUDE_INSTALL_DIR
)
