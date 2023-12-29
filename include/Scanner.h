#pragma once

#include <string>
#include <vector>

#include "Literal.h"
#include "Token.h"

class Scanner {
   public:
    Scanner(std::string source) : source(source), tokens(){};
    std::vector<Token> scan_tokens();

   private:
    std::string source;
    std::vector<Token> tokens;
    size_t start = 0;
    size_t current = 0;
    size_t line = 1;

    void scan_token();
    void add_token(TokenType type);
    void add_token(TokenType type, Literal literal);
    void scan_string();
    void scan_number();
    void scan_identifier();

    bool is_at_end() const;
    char advance();
    bool match(char expected);
    char peek() const;
    char peek_next() const;
};
