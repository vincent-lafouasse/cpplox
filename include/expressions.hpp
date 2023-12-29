#pragma once

#include "Token.h"
#include "Literal.h"

struct Expression {};

struct BinaryExpression : Expression
{
	Expression left;
	Token op;
	Expression right;
};

struct UnaryExpression : Expression
{
	Token op;
	Expression right;
};
