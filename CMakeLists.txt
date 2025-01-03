# specify a minimum cmake version
cmake_minimum_required(VERSION 3.10)

# names your project Example and signals that it is a c++ project
project(Example LANGUAGES CXX)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)

# -----------------------------
include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest.git
   GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# add executables from your source files
add_executable(Example 
   # add the files here
   src/main.cpp
)

# add include direcotry for headers for compiler
target_include_directories(Example
   PRIVATE
      ${PROJECT_SOURCE_DIR}/include
)

#--------------------------------
# create test executable
add_executable(AllTests
   tests/test_main.cpp
   # add more tests here
)

target_include_directories(AllTests PRIVATE include)
target_link_libraries(AllTests PRIVATE gtest_main)
add_test(NAME AllTests COMMAND AllTests)
