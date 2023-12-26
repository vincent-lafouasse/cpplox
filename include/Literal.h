#pragma once

#include <variant>
#include <string>

typedef std::variant<std::string, int, unsigned int, char, double> Literal;
