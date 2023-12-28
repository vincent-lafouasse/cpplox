#pragma once

#include <string>
#include <variant>

class Literal
{
	Literal(const std::string& string_literal);
	Literal(double x);
private:
	std::variant<std::string, double> data;
};
