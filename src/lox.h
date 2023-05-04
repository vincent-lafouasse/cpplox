#pragma once

#include <string>

class Lox {
 public:
  static void main(int argc, char* argv[]);
  static void error(int line, std::string message);

 private:
  static bool had_error;

  static void run(std::string source);
  static void run_prompt(void);
  static void run_file(std::string path);
  static void report(int line, std::string where, std::string message);
};
