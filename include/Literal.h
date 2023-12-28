#pragma once

#include <string>
#include <variant>

typedef std::variant<std::string, int, unsigned int, char, double> Literal;
