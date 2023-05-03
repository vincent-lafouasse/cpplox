#pragma once

#include <string>
#include <vector>

#include "token.h"

class Scanner {
 public:
  Scanner(std::string source_);

 private:
  std::string source;
  std::vector<Token> tokens;
};
