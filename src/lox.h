#pragma once

#include <string>

class Lox {
 public:
  static void main(int argc, char* argv[]);

 private:
  static void run(std::string source);
  static void run_prompt(void);
  static void run_file(std::string path);
};
