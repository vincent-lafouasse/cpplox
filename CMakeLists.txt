cmake_minimum_required(VERSION 3.5)

project(cpplox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

add_executable(cpplox
src/lox.cpp
src/main.cpp
src/scanner.cpp
src/token.cpp
src/token_type.cpp
)
target_compile_options(cpplox PUBLIC -Wall -Wextra -Wpedantic -g3)
target_include_directories(cpplox PUBLIC include)

