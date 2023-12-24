cmake_minimum_required(VERSION 3.5)

project(cpplox)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)


add_executable(cpplox
src/lox.cpp
src/main.cpp
src/scanner.cpp
src/token.cpp
src/token_type.cpp
)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
