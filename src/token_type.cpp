#include "token_type.h"

#include <unordered_map>

std::unordered_map<TokenType, std::string> TOKEN_TYPE_TO_STR = {
    {TokenType::LEFT_PAREN, "LeftParen"},
    {TokenType::RIGHT_PAREN, "RightParen"},
    {TokenType::LEFT_BRACE, "LeftBrace"},
    {TokenType::RIGHT_BRACE, "RightBrace"},
    {TokenType::COMMA, "Comma"},
    {TokenType::DOT, "Dot"},
    {TokenType::MINUS, "Minus"},
    {TokenType::PLUS, "Plus"},
    {TokenType::SEMICOLON, "Semicolon"},
    {TokenType::SLASH, "Slash"},
    {TokenType::STAR, "Star"},
    {TokenType::BANG, "Bang"},
    {TokenType::BANG_EQUAL, "BangEqual"},
    {TokenType::EQUAL, "Equal"},
    {TokenType::EQUAL_EQUAL, "EqualEqual"},
    {TokenType::GREATER, "Greater"},
    {TokenType::GREATER_EQUAL, "GreaterEqual"},
    {TokenType::LESS, "Less"},
    {TokenType::LESS_EQUAL, "LessEqual"},
    {TokenType::IDENTIFIER, "Identifier"},
    {TokenType::STRING, "String"},
    {TokenType::NUMBER, "Number"},
    {TokenType::AND, "And"},
    {TokenType::CLASS, "Class"},
    {TokenType::ELSE, "Else"},
    {TokenType::FALSE, "False"},
    {TokenType::FUN, "Fun"},
    {TokenType::FOR, "For"},
    {TokenType::IF, "If"},
    {TokenType::NIL, "Nil"},
    {TokenType::OR, "Or"},
    {TokenType::PRINT, "Print"},
    {TokenType::RETURN, "Return"},
    {TokenType::SUPER, "Super"},
    {TokenType::THIS, "This"},
    {TokenType::TRUE, "True"},
    {TokenType::VAR, "Var"},
    {TokenType::WHILE, "While"},
    {TokenType::EOF_, "EOF"},
};

std::string token_type_to_str(TokenType type) {
  return TOKEN_TYPE_TO_STR[type];
}
