cmake_minimum_required (VERSION 3.5)
project(FolderUpdater)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

file(GLOB CPP_FILES src/*.cpp)
file(GLOB H_FILES include/*.h)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")


add_executable(FolderUpdater ${CPP_FILES} ${H_FILES})

target_include_directories(FolderUpdater PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(FolderUpdater Qt5::Core)