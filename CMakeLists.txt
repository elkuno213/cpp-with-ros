# ──────────────────────────────────────────────────────────────────────────── #
# Project                                                                      #

cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)
project(cpp-with-ros LANGUAGES CXX VERSION 1.0.0)
include(CMakePackageConfigHelpers)





# ──────────────────────────────────────────────────────────────────────────── #
# Flags                                                                        #
# Define CMake flags related to C++, some compilation flags and library flags  #

# CMake flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
# set(CMAKE_EXE_LINKER_FLAGS " -fsanitize=address")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_PREFIX "/opt/hvh")

# Compilation flags
if(MSVC)
  # MSVC https://msdn.microsoft.com/en-us/library/thxezb7y.aspx
  add_compile_options(/MP /W4 /WX)
else()
  # Gcc   https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
  # Clang http://clang.llvm.org/docs/UsersManual.html
  add_compile_options(-fdiagnostics-show-option -Wall -Wextra -pedantic -Werror)
endif()

# Boost flags
set(Boost_NO_WARN_NEW_VERSIONS 1) # Deactivate warning due to version conflicts of Boost and CMake
set(Boost_USE_STATIC_LIBS ON)     # Only find static libs
set(Boost_USE_DEBUG_LIBS OFF)     # Ignore debug libs and
set(Boost_USE_RELEASE_LIBS ON)    # Only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)  # Link Boost Static libraries




# ──────────────────────────────────────────────────────────────────────────── #
# Conda integration                                                            #
# The default conda location is installed at `/opt/miniconda3`                 #
# The default conda environment used is `common`                               #

# Find Python executable of conda env `common`.
# It helps to link CMake to the correct Python Interpreter while VSCode's CMake
# Tools does not work with auto-selected Python Interpreter by VSCode
# Reference: https://cmake.org/cmake/help/latest/module/FindPython.html
set(
  Python_ROOT_DIR "/opt/miniconda3/envs/common/bin/"
  CACHE PATH "The root directory of a Python installation" FORCE
)
find_package(Python REQUIRED COMPONENTS Interpreter Development)




# ──────────────────────────────────────────────────────────────────────────── #
# ROS integration                                                              #
# ROS is by default installed at `/opt/ros/noetic`                             #

# Find ROS packages.
set(CATKIN_ENABLE_TESTING OFF)
set(PYTHON_EXECUTABLE ${Python_EXECUTABLE}) # For catkin
set(ENV{ROS_LANG_DISABLE} "geneus:genlisp:gennodejs") # Do NOT generate messages in Euslisp, Lisp, JavaScript
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rosbag
  std_msgs
  sensor_msgs
  geometry_msgs
  map_msgs
  actionlib_msgs
  actionlib
  message_generation
)

# Add include directories.
include_directories(${catkin_INCLUDE_DIRS})




# ──────────────────────────────────────────────────────────────────────────── #
# Vcpkg integration                                                            #
# Vcpkg is by default installed at `/opt/vcpkg`                                #

# Integrate vcpkg toolchain
set(
  CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE FILEPATH "Configuration CMake file of Vcpkg toolchain" FORCE
)
include(${CMAKE_TOOLCHAIN_FILE})
include_directories(${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include)

# Find packages
find_package(Boost REQUIRED COMPONENTS
  atomic
  chrono
  container
  context
  coroutine
  date_time
  exception
  fiber
  filesystem
  graph
  iostreams
  locale
  log
  program_options
  random
  regex
  serialization
  system
  thread
  timer
  wave
)




# ──────────────────────────────────────────────────────────────────────────── #
# Add libraries and targets #

add_subdirectory(localization_with_ros)




# ──────────────────────────────────────────────────────────────────────────── #
# Uninstallation #

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
