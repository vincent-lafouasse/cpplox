#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <variant>

#define STRING_INDEX 0
#define DOUBLE_INDEX 1

typedef void* None;

using StrDoubleVariant = std::variant<std::string, double, None>;

struct Literal : StrDoubleVariant
{
    using StrDoubleVariant::StrDoubleVariant;
    using StrDoubleVariant::operator=;

    // Literal(const Literal&) = default;
    // Literal(Literal&&) = delete;

    inline bool operator==(std::nullptr_t) const
    {
        return std::holds_alternative<None>(*this);
    }
    inline bool operator==(const Literal& other) const
    {
        if (std::holds_alternative<std::string>(*this) &&
            std::holds_alternative<std::string>(other))
            return std::get<std::string>(*this) == std::get<std::string>(other);
        if (std::holds_alternative<double>(*this) &&
            std::holds_alternative<double>(other))
            return std::get<double>(*this) == std::get<double>(other);
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Literal& literal);
};
