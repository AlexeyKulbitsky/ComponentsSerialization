cmake_minimum_required(VERSION 3.4.1)

project (Framework)

add_subdirectory(../engine "${CMAKE_CURRENT_BINARY_DIR}/engine_build")
include_directories(../engine/source)

file(GLOB_RECURSE FRAMEWORK_SRC "source/*.h" "source/*.hpp" "source/*.cpp")

# Group files according to files organization
foreach(FILE ${FRAMEWORK_SRC}) 
      # Get the directory of the source file
      get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

      # Remove common directory prefix to make the group
      string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

      # Make sure we are using windows slashes
      string(REPLACE "/" "\\" GROUP "${GROUP}")

      source_group("${GROUP}" FILES "${FILE}")
endforeach()
  
add_executable(framework ${FRAMEWORK_SRC})
target_link_libraries(framework Engine)


