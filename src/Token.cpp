#include "Token.h"

#include <sstream>
std::string Token::to_string(void) const
{
    std::stringstream sstream;
    if (literal.is_none())
        sstream << type;
    else if (literal.is_string())
        sstream << "str'" << literal.as_string();
    else if (literal.is_double())
        sstream << "num'" << literal.as_double();
    return sstream.str();
}
