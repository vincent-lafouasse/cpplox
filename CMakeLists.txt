cmake_minimum_required(VERSION 3.5)

project(cpplox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE) # LSP stuff, don't worry about it

add_executable(cpplox
src/Lox.cpp
src/main.cpp
src/Scanner.cpp
src/Token.cpp
src/TokenType.cpp
src/literal.cpp
)
target_compile_options(cpplox PUBLIC -Wall -Wextra -Wpedantic -g3)
target_include_directories(cpplox PUBLIC include)

