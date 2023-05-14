# ──────────────────────────────────────────────────────────────────────────── #
# Library #

add_library(
  ${PROJECT_NAME} SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/localizer.cpp
)
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(${PROJECT_NAME} PUBLIC
  ${catkin_LIBRARIES}
)




# ──────────────────────────────────────────────────────────────────────────── #
# Installation #

# Install non-ROS targets
install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION ${ROS_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${ROS_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${ROS_INSTALL_LIBDIR}
)

# Install only the header files for the library
install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/
  DESTINATION ${ROS_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN "*.h"
  PATTERN "*.hpp"
)
