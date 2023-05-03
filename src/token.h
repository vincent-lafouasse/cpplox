#pragma once

#include "token_type.h"

#include <string>

class Token {
 private:
  TokenType type;
  std::string lexeme;
  // Object literal;
  int line;

 public:
  Token(TokenType type_, std::string lexeme_, /*Object literal_,*/ int line_);
  std::string to_string(void);
};
