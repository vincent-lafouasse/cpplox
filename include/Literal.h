#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <variant>

class None
{
};

using StrDoubleVariant = std::variant<std::string, double, None>;

struct Literal : StrDoubleVariant
{
    using StrDoubleVariant::StrDoubleVariant;
    using StrDoubleVariant::operator=;

    // Literal(const Literal&) = default;
    // Literal(Literal&&) = delete;

    std::string as_string() const;
    double as_double() const;
    bool is_string() const;
    bool is_double() const;
    bool is_none() const;

    inline bool operator==(const Literal& other) const
    {
        if (this->is_string() && other.is_string())
            return this->as_string() == other.as_string();
        if (this->is_double() && other.is_double())
            return this->as_double() == other.as_double();
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Literal& literal);
};
