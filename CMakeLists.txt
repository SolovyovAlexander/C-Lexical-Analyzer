cmake_minimum_required(VERSION 3.13)
project(Lexical_analayzer_for_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Lexical_analayzer_for_C scanner.h scanner.c token.c token.h main.c)