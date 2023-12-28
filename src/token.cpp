#include "token.h"

#include <sstream>

Token::Token(TokenType type_,
             std::string lexeme_,
             std::string literal_,
             int line_)
{
    type = type_;
    lexeme = lexeme_;
    literal = literal_;
    line = line_;
}

std::string Token::to_string(void) const
{
    std::stringstream sstream;
    sstream << token_type_to_str(type) << " " << lexeme << " "
            << "placeholder for literal";
    return sstream.str();
}
