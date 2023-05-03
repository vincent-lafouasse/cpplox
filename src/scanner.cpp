#include "scanner.h"

#include <iostream>

Scanner::Scanner(std::string source_) {
  source = source_;
}

std::vector<Token> Scanner::scan_tokens() {
  while (!is_at_end()) {
    start = current;
    scan_token();
  }
  tokens.push_back(Token(TokenType::EOF_, "", "", line));
  return tokens;
}

void Scanner::scan_token() {}

bool Scanner::is_at_end() {
  return current >= source.size();
}
