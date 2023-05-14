# The configuration below follows the filesystem structure of ROS Catkin so
# that ROS can find out packages

set(
  ROS_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
  CACHE PATH "Include directory of install location" FORCE
)
set(
  ROS_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
  CACHE PATH "Library directory of install location" FORCE
)
set(
  ROS_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin
  CACHE PATH "Binary directory of install location" FORCE
)
set(
  ROS_INSTALL_SHAREDIR ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
  CACHE PATH "Share directory of install location" FORCE
)
set(
  ROS_INSTALL_LAUNCHDIR ${ROS_INSTALL_SHAREDIR}/launch
  CACHE PATH "directory containing launch files of install location" FORCE
)
set(
  ROS_INSTALL_CMAKEDIR ${ROS_INSTALL_SHAREDIR}/cmake
  CACHE PATH "CMake configuration directory of install location" FORCE
)
