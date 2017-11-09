cmake_minimum_required(VERSION 3.4.1)

project (Engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/source)
set(PROJECT_NAME Engine)

include_directories( ${PROJECT_INCLUDE_DIR} )

file(GLOB_RECURSE PROJECT_SOURCE_FILES "source/*.h" "source/*.hpp" "source/*.cpp")

# Group files according to files organization
foreach(FILE ${PROJECT_SOURCE_FILES}) 
    # Get the directory of the source file
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

    # Remove common directory prefix to make the group
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    source_group("${GROUP}" FILES "${FILE}")
endforeach()


add_library(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})



