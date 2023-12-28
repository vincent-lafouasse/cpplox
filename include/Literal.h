#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <variant>

#define STRING_INDEX 0
#define DOUBLE_INDEX 1

class Literal
{
    Literal(const std::string& string_literal) : data(string_literal){};
    Literal(double x) : data(x){};
    friend std::ostream& operator<<(std::ostream& os, const Literal& literal);

   private:
    std::variant<std::string, double> data;
};
