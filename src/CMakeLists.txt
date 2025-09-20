# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.h")
# set(HEADER_LIST "${ModernCMakeExample_SOURCE_DIR}/include/modern/lib.hpp")

AUX_SOURCE_DIRECTORY(. SRC_LIST)
AUX_SOURCE_DIRECTORY(./tools SRC_LIST)
AUX_SOURCE_DIRECTORY(./timestepper SRC_LIST)
add_library(${simulator_name} ${SRC_LIST})
target_link_libraries(${simulator_name} Eigen3::Eigen polyscope)
target_include_directories(${simulator_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

# IDEs should put the headers in a nice place
# source_group(
#   TREE "${PROJECT_SOURCE_DIR}/include"
#   PREFIX "Header Files"
#   FILES ${HEADER_LIST})

