#pragma once

#include "token_type.h"

#include <string>

class Token
{
   private:
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;

   public:
    Token(TokenType type, std::string lexeme, std::string literal, int line);
    std::string to_string(void) const;
};
