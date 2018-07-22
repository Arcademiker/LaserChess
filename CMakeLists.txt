cmake_minimum_required(VERSION 3.7)
project(LaserChess)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CMap.cpp CMap.h CUnit.cpp CUnit.h CUnit_AI.cpp CUnit_AI.h Units/CDreadnought.cpp Units/CDreadnought.h CUnit_Player.cpp CUnit_Player.h Units/CGrunt.cpp Units/CGrunt.h Units/CJumpship.cpp Units/CJumpship.h Units/CTank.cpp Units/CTank.h Units/CDrone.cpp Units/CDrone.h Units/CCommandUnit.cpp Units/CCommandUnit.h)
add_executable(LaserChess ${SOURCE_FILES})