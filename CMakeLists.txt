cmake_minimum_required(VERSION 3.16)

project(jeu_de_vie LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(jeu_de_vie main.cpp
    GameOfLife.cc
    GameOfLife.hh
    grid.cc
    grid.hh)

include(GNUInstallDirs)
install(TARGETS jeu_de_vie
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
