cmake_minimum_required(VERSION 3.4.1)

project (Engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_NAME Engine)

include_directories( ${PROJECT_INCLUDE_DIR} )

file(GLOB_RECURSE PROJECT_SOURCE_FILES "source/*.cpp")


add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES})



