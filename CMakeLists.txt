cmake_minimum_required(VERSION 3.10)
project(CppFetch)

set(CMAKE_CXX_STANDARD 20)

add_executable(cppfetch src/main.cpp src/helpers/functions.cpp
  src/info/cpu.cpp src/info/distro.cpp src/info/environment.cpp
  src/info/memory.cpp src/info/packages.cpp src/info/term.cpp
  src/info/uptime.cpp)
