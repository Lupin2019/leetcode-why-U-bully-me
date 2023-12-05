cmake_minimum_required(VERSION 3.22)

project(001)

# DEFINE
add_compile_definitions(PROJECT_DIR=${PROJECT_SOURCE_DIR})

option(USE_GDB "Use GDB" OFF)

# gdb
if(${USE_GDB})
  set(CMAKE_BUILD_TYPE "Debug")
  set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
  set(CMAKE_C_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
endif()


set(SRC_PATH ${PROJECT_SOURCE_DIR}/src)
set(DEMO_PATH ${PROJECT_SOURCE_DIR}/demo) 
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)

file(GLOB SRC_FILES
  "${DEMO_PATH}/*.cpp" 
  "${DEMO_PATH}/*.c" 
)

foreach(FILE_PATH ${SRC_FILES})
  message("file_path: " ${FILE_PATH})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
  message("file_name: " ${FILE_NAME})
  add_executable(${PROJECT_NAME}_${FILE_NAME} ${FILE_PATH})
  target_link_libraries(${PROJECT_NAME}_${FILE_NAME} m)
endforeach()