#include "Token.h"

#include <sstream>
std::string Token::to_string(void) const
{
    std::stringstream sstream;
    sstream << type << " " << lexeme << " " << literal;
    return sstream.str();
}
