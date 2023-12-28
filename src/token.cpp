#include "token.h"

#include <sstream>

Token::Token(TokenType type, std::string lexeme, std::string literal, int line)
{
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
}

std::string Token::to_string(void) const
{
    std::stringstream sstream;
    sstream << token_type_to_str(type) << " " << lexeme << " " << literal;
    return sstream.str();
}
