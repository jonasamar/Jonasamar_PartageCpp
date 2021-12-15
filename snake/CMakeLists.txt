cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(snake main.cpp init_background.cpp affichage.cpp serpent.cpp place_point_serpent.cpp place_point_background.cpp place_serpent.cpp init_game.cpp move_left.cpp move_right.cpp move_up.cpp move_down.cpp keyboard.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
