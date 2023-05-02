#include "lox.h"

#include <fstream>
#include <iostream>
#include <sstream>

static std::string load_file(std::string path);

void Lox::main(int argc, char* argv[]) {
  if (argc > 2) {
    std::cout << "Usage: cpplox [script]" << std::endl;
    exit(64);
  } else if (argc == 2) {
    run_file(argv[1]);
  } else {
    run_prompt();
  }
}

void Lox::run(std::string source) {
  std::cout << source << std::endl;
}

void Lox::run_prompt(void) {
  std::string input;

  for (;;) {
    std::cout << "> ";
    std::getline(std::cin, input);
    if (input == "")
      break;
    run(input);
  }
}

void Lox::run_file(std::string path) {
  run(load_file(path));
}

static std::string load_file(std::string path) {
  std::ifstream file_stream(path);
  std::stringstream str_stream;
  str_stream << file_stream.rdbuf();
  return str_stream.str();
}
