# CMakeLists.txt for the hashtable project
cmake_minimum_required(VERSION 3.20)

# Ensure we can use gdb
set(CMAKE_BUILD_TYPE Debug)

project(project2a-hashtable)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# Retrieve the wordlist used by the tests and copy to build directory
file(
  DOWNLOAD https://github.com/brokensandals/wordlists/blob/master/lists/enable1.txt ./dictionary.txt 
  EXPECTED_HASH MD5=9c5811880e43c73b20434ba2f33f0367
)
file(COPY dictionary.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_compile_options(-pedantic -Wall -Wextra -Werror=vla)

add_executable(run-main hashtable.h main.cpp hash_functions.h hash_functions.cpp random220.h random220.cpp)

