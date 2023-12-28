#include "Literal.h"

std::ostream& operator<<(std::ostream& os, const Literal& literal)
{
    if (literal == nullptr)
        return os;
    switch (literal.index())
    {
        case STRING_INDEX:
            os << std::get<STRING_INDEX>(literal);
            break;
        case DOUBLE_INDEX:
            os << std::get<DOUBLE_INDEX>(literal);
            break;
        default:
            break;
    }
    return os;
}
