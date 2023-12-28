#include "Literal.h"

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
