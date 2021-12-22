# CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(driver)

# Define the search path for header files

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()    
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Define the executable
add_executable(${PROJECT_NAME}
               src/driver.cpp
               src/uncopyable.cpp
               src/juniorDriver.cpp
               src/lock.cpp)
