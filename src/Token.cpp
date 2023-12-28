#include "Token.h"

#include <sstream>
std::string Token::to_string(void) const
{
    std::stringstream sstream;
    if (std::holds_alternative<void*>(literal))
        sstream << type;
    else if (std::holds_alternative<std::string>(literal))
        sstream << std::get<std::string>(literal);
    if (std::holds_alternative<double>(literal))
        sstream << std::get<double>(literal);
    return sstream.str();
}
