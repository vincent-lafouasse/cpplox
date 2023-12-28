#include "Literal.h"

#define STRING_INDEX 0
#define DOUBLE_INDEX 1
#define NONE_INDEX 2

double Literal::as_double() const
{
    return std::get<double>(*this);
}

std::string Literal::as_string() const
{
    return std::get<std::string>(*this);
}

bool Literal::is_string() const
{
    return std::holds_alternative<std::string>(*this);
}

bool Literal::is_double() const
{
    return std::holds_alternative<double>(*this);
}

bool Literal::is_none() const
{
    return std::holds_alternative<None>(*this);
}

std::ostream& operator<<(std::ostream& os, const Literal& literal)
{
    switch (literal.index())
    {
        case STRING_INDEX:
            os << std::get<STRING_INDEX>(literal);
            break;
        case DOUBLE_INDEX:
            os << std::get<DOUBLE_INDEX>(literal);
            break;
        case NONE_INDEX:
        default:
            break;
    }
    return os;
}
