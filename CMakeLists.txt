cmake_minimum_required(VERSION 3.17)
project(othello C)

set(CMAKE_C_STANDARD 11)

add_executable(othello main.c flip.h flip.c logic.h logic.c board.c board.h play.h play.c)