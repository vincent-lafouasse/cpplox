#include "token_type.h"

#include <unordered_map>

std::unordered_map<TokenType, std::string> TOKEN_TYPE_TO_STR = {
    {TokenType::LeftParen, "LeftParen"},
    {TokenType::RightParen, "RightParen"},
    {TokenType::LeftBrace, "LeftBrace"},
    {TokenType::RightBrace, "RightBrace"},
    {TokenType::Comma, "Comma"},
    {TokenType::Dot, "Dot"},
    {TokenType::Minus, "Minus"},
    {TokenType::Plus, "Plus"},
    {TokenType::Semicolon, "Semicolon"},
    {TokenType::Slash, "Slash"},
    {TokenType::Star, "Star"},
    {TokenType::Bang, "Bang"},
    {TokenType::BangEqual, "BangEqual"},
    {TokenType::Equal, "Equal"},
    {TokenType::EqualEqual, "EqualEqual"},
    {TokenType::Greater, "Greater"},
    {TokenType::GreaterEqual, "GreaterEqual"},
    {TokenType::Less, "Less"},
    {TokenType::LessEqual, "LessEqual"},
    {TokenType::Identifier, "Identifier"},
    {TokenType::String, "String"},
    {TokenType::Number, "Number"},
    {TokenType::And, "And"},
    {TokenType::Class, "Class"},
    {TokenType::Else, "Else"},
    {TokenType::False, "False"},
    {TokenType::Fun, "Fun"},
    {TokenType::For, "For"},
    {TokenType::If, "If"},
    {TokenType::Nil, "Nil"},
    {TokenType::Or, "Or"},
    {TokenType::Print, "Print"},
    {TokenType::Return, "Return"},
    {TokenType::Super, "Super"},
    {TokenType::This, "This"},
    {TokenType::True, "True"},
    {TokenType::Var, "Var"},
    {TokenType::While, "While"},
    {TokenType::EOF_, "EOF"},
};

std::string token_type_to_str(TokenType type)
{
    return TOKEN_TYPE_TO_STR[type];
}
