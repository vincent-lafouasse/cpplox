#pragma once

#include <string>
#include <vector>

#include "token.h"

class Scanner {
 public:
  Scanner(std::string source_);
  std::vector<Token> scan_tokens();

 private:
  std::string source;
  std::vector<Token> tokens;
  size_t start = 0;
  size_t current = 0;
  size_t line = 1;

  void scan_token();
  bool is_at_end();
  char advance();
  void add_token(TokenType type);
  void add_token(TokenType type, std::string literal);
};
