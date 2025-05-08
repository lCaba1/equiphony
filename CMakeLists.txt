cmake_minimum_required(VERSION 3.10)
project(equiphony2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB SRC_LIST "source/*")

add_executable(${PROJECT_NAME} ${SRC_LIST})

#CXX=clang++ cmake -GNinja -DCMAKE_BUILD_TYPE=Debug ..
#ninja -v
#make
#lldb ./