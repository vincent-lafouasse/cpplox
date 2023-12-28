#include "Literal.h"

std::ostream& operator<<(std::ostream& os, const Literal& literal)
{
    switch (literal.data.index())
    {
        case STRING_INDEX:
            os << std::get<STRING_INDEX>(literal.data);
            break;
        case DOUBLE_INDEX:
            os << std::get<DOUBLE_INDEX>(literal.data);
            break;
        default:
            break;
    }
    return os;
}
