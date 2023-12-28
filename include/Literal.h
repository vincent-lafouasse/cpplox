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

    std::string as_string() const;
    double as_double() const;
    bool is_string() const;
    bool is_double() const;
    bool is_none() const;

    bool operator==(const Literal& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Literal& literal);
};
