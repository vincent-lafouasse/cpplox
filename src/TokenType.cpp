#include "TokenType.h"

#include <unordered_map>

const std::unordered_map<TokenType, std::string> TOKEN_TYPE_TO_STR = {
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

std::ostream& operator<<(std::ostream& os, const TokenType& type)
{
    os << TOKEN_TYPE_TO_STR.at(type);
    return os;
}

const std::unordered_map<std::string, TokenType> KEYWORDS = {
    {"and", TokenType::And},       {"class", TokenType::Class},
    {"else", TokenType::Else},     {"false", TokenType::False},
    {"for", TokenType::For},       {"fun", TokenType::Fun},
    {"if", TokenType::If},         {"nil", TokenType::Nil},
    {"or", TokenType::Or},         {"print", TokenType::Print},
    {"return", TokenType::Return}, {"super", TokenType::Super},
    {"this", TokenType::This},     {"true", TokenType::True},
    {"var", TokenType::Var},       {"while", TokenType::While},
};

std::optional<TokenType> get_keyword(const std::string& type)
{
    auto match = KEYWORDS.find(type);

    if (match == KEYWORDS.cend())
    {
        std::cout << "not a keyword\n";
        return {};
    }
    return match->second;
}
