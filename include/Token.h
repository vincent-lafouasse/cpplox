#pragma once

#include "Literal.h"
#include "TokenType.h"

#include <string>

class Token
{
   private:
    TokenType type;
    std::string lexeme;
    Literal literal;
    int line;

   public:
    Token() = default;
    Token(TokenType type, std::string lexeme, Literal literal, int line)
        : type(type), lexeme(lexeme), literal(literal), line(line){};
    Token(const Token& other) = default;
    Token(Token&& other) = default;
    std::string to_string(void) const;
};
