cmake_minimum_required(VERSION 3.14)
project(Lexical_analayzer_for_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Lexical_analayzer_for_C main.c scanner.c scanner.h token.c token.h)