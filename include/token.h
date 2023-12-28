#pragma once

#include "Literal.h"
#include "token_type.h"

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
    Token(Token& other)
        : type(other.type),
          lexeme(other.lexeme),
          literal(other.literal),
          line(other.line){};
    std::string to_string(void) const;

    Token& operator=(const Token& other)  // III. copy assignment
    {
        if (this == &other)
            return *this;

        this->line = other.line;
        this->lexeme = other.lexeme;
        this->literal = other.literal;
        this->type = other.type;
        return *this;
    }
};
