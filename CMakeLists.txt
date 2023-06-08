cmake_minimum_required(VERSION 3.23)
project(BASIC)

set(CMAKE_CXX_STANDARD 14)

add_executable(BASIC main.cpp Command.cpp Command.h Input.cpp Input.h Print.cpp Print.h Let.cpp Let.h Goto.cpp Goto.h If.cpp If.h Program.cpp Program.h)
