cmake_minimum_required(VERSION 3.7)
project(LaserChess)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CMap.cpp CMap.h CUnit.cpp CUnit.h CUnit_AI.cpp CUnit_AI.h CDreadnought.cpp CDreadnought.h CUnit_Player.cpp CUnit_Player.h)
add_executable(LaserChess ${SOURCE_FILES})