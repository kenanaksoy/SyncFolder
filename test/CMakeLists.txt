cmake_minimum_required (VERSION 3.5)
project(KenanFileCopyTest)

set (GMOCK_PATH "" CACHE STRING "")

link_directories("${GMOCK_PATH}/lib64")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

file(GLOB TEST_FILES src/*.cpp)
file(GLOB PROJECT_SOURCE_FILES ../FolderUpdater/src/*.cpp)

LIST(REMOVE_ITEM PROJECT_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../FolderUpdater/src/Main.cpp)
file(GLOB PROJECT_HEADER_FILES ../FolderUpdater/include/*.h)

add_executable(KenanFileCopyTest ${TEST_FILES} ${PROJECT_HEADER_FILES} ${PROJECT_SOURCE_FILES})

target_include_directories(KenanFileCopyTest PRIVATE "${GMOCK_PATH}/include" PRIVATE "../FolderUpdater/include")
target_link_libraries(KenanFileCopyTest gmock)