cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++98")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")

project (tentacle)

file(GLOB SRCS *.cpp *.hpp *.c *.h)

add_library(tentacle STATIC ${SRCS})

include_directories( tentacle
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

set(TENTACLE_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

set_target_properties(tentacle PROPERTIES ENABLE_EXPORTS true)
