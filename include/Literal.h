#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <variant>

#define STRING_INDEX 0
#define DOUBLE_INDEX 1

class Literal
{
   public:
    Literal() : data(){};
    Literal(const std::string& string_literal) : data(string_literal){};
    Literal(double x) : data(x){};
    Literal(Literal& other) : data(other.data){};
    Literal& operator=(const Literal& other)  // III. copy assignment
    {
        if (this == &other)
            return *this;

        this->data = other.data;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Literal& literal);

   private:
    std::variant<std::string, double> data;
};
