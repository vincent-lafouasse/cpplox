#pragma once

#include <string>

class Lox {
 public:
  void main(int argc, char* argv[]);
  void error(int line, std::string message);

 private:
  bool had_error = false;

  void run(std::string source);
  void run_prompt(void);
  void run_file(std::string path);
  void report(int line, std::string where, std::string message);
};
