# Example C++ project

This project demonstrates a simple **C++ application** built with **CMake**, tested with **Google Test**, and managed with **Git**.

# 1 Create structure
```
Project
  CMakeLists.txt
  src/
    main.cpp
  include/
    header_file1.h
    header_file2.h
  build/
  tests/
```


# 2 Complete CMakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES CXX)

# Use a modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------
# 1. Enable testing with CTest
# --------------------------------------------------------
include(CTest)
enable_testing()

# --------------------------------------------------------
# 2. Fetch Google Test (no manual install needed)
# --------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# --------------------------------------------------------
# 3. Main Executable
# --------------------------------------------------------
add_executable(MyProject
    # add all src files here
    src/main.cpp
)
target_include_directories(MyProject PRIVATE include)

# --------------------------------------------------------
# 4. Test Executable
# --------------------------------------------------------
add_executable(AllTests
    # add all tests here
    tests/test_main.cpp
)
target_include_directories(AllTests PRIVATE include)
target_link_libraries(AllTests PRIVATE gtest_main)

add_test(NAME AllTests COMMAND AllTests)
```

# 3 Create .gitignore
```
# Ignore build artifacts, caches, etc.
build/
CMakeFiles/
CMakeCache.txt

# Ignore OS/IDE-specific files
.DS_Store
*.sln
*.vcxproj
*.xcodeproj

# Ignore compiled objects and executables
*.o
*.obj
*.exe
*.dll
*.so
*.dylib
```

# 4 Build the project

## move into the build directory
```
cd buid
```
## run cmake to generate build files
```
cmake ..
```
## build
```
cmake --build .
```









