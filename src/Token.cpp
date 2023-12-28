#include "Token.h"

#include <sstream>
std::string Token::to_string(void) const
{
    std::stringstream sstream;
    sstream << token_type_to_str(type) << " " << lexeme << " " << literal;
    return sstream.str();
}
