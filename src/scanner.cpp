#include "scanner.h"

#include <iostream>

#include "lox.h"

Scanner::Scanner(std::string source_) {
  source = source_;
}

std::vector<Token> Scanner::scan_tokens() {
  while (!is_at_end()) {
    start = current;
    scan_token();
    std::cout << "scanning" << std::endl;
  }
  tokens.push_back(Token(TokenType::EOF_, "", "", line));
  return tokens;
}

void Scanner::scan_token() {
  char c = advance();

  switch (c) {
		case '(': add_token(TokenType::LEFT_PAREN); break;
		case ')': add_token(TokenType::RIGHT_PAREN); break;
		case '{': add_token(TokenType::LEFT_BRACE); break;
		case '}': add_token(TokenType::RIGHT_BRACE); break;
		case ',': add_token(TokenType::COMMA); break;
		case '.': add_token(TokenType::DOT); break;
		case '-': add_token(TokenType::MINUS); break;
		case '+': add_token(TokenType::PLUS); break;
		case ';': add_token(TokenType::SEMICOLON); break;
		case '*': add_token(TokenType::STAR); break;
  }
}

bool Scanner::is_at_end() {
  return current >= source.size();
}

char Scanner::advance() {
  return source.at(current++);
}

void Scanner::add_token(TokenType type) {
  add_token(type, "");
}

void Scanner::add_token(TokenType type, std::string literal) {
  tokens.push_back(Token(type, source.substr(start, current), literal, line));
}
