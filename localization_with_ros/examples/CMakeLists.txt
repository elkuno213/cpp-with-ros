# ──────────────────────────────────────────────────────────────────────────── #
# Add executables #

# Build an executable that provides some data (talking)
add_executable(talker_node ${CMAKE_CURRENT_SOURCE_DIR}/talker_node.cpp)
target_link_libraries(talker_node PUBLIC
  ${catkin_LIBRARIES}
)

# Build an executable that receives some data (listening)
add_executable(listener_node ${CMAKE_CURRENT_SOURCE_DIR}/listener_node.cpp)
target_link_libraries(listener_node PUBLIC
  ${catkin_LIBRARIES}
)

# Build an executable that use existing messages.
add_executable(use_existing_msg ${CMAKE_CURRENT_SOURCE_DIR}/use_existing_msg.cpp)

# Build an executable that uses our messages, making it depend on the
# message-generation step.
add_executable(use_custom_msg ${CMAKE_CURRENT_SOURCE_DIR}/use_custom_msg.cpp)
add_dependencies(use_custom_msg ${PROJECT_NAME}_generate_messages)

# Build an executable that use existing service.
add_executable(use_existing_srv ${CMAKE_CURRENT_SOURCE_DIR}/use_existing_srv.cpp)

# Build an executable that uses our messages, making it depend on the
# message-generation step.
add_executable(use_custom_srv ${CMAKE_CURRENT_SOURCE_DIR}/use_custom_srv.cpp)
add_dependencies(use_custom_srv ${PROJECT_NAME}_generate_messages)

# Build action executables of client and server
add_executable(actionclient ${CMAKE_CURRENT_SOURCE_DIR}/actionclient.cpp)
target_link_libraries(actionclient
  ${catkin_LIBRARIES}
)
add_dependencies(actionclient ${PROJECT_NAME}_generate_messages)

add_executable(actionserver ${CMAKE_CURRENT_SOURCE_DIR}/actionserver.cpp)
target_link_libraries(actionserver
  ${catkin_LIBRARIES}
)
add_dependencies(actionserver ${PROJECT_NAME}_generate_messages)

# ──────────────────────────────────────────────────────────────────────────── #
# Installation #

# Install libs and binaries that are related to ROS (e.g. nodes)
install(
  TARGETS talker_node listener_node
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION ${ROS_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${ROS_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${ROS_INSTALL_LIBDIR}
)

# Install binaries that are not related to ROS
install(
  TARGETS use_existing_msg use_custom_msg
  use_existing_srv use_custom_srv
  actionclient actionserver
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION ${ROS_INSTALL_BINDIR}
)
