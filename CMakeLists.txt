# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)
set(project_name BP_Demo)
set(CMAKE_CXX_STANDARD 17)

# Set the project name
project (BP_Demo)

# Create a sources variable with a link to all cpp files to compile


# Add an executable with the above sources


# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/

find_package (gflags REQUIRED)
find_package (glog REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(./src SOURCE_DIR)
add_subdirectory(./include/network)
add_executable (${project_name} ${SOURCE_DIR})
# add_library(test SHARED ${SOURCE_DIR})

target_link_libraries(${project_name} NetWork glog gflags)