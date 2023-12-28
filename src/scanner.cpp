#include "scanner.h"

#include <iostream>

#include "lox.h"

Scanner::Scanner(std::string source_)
{
    source = source_;
}

std::vector<Token> Scanner::scan_tokens()
{
    while (!is_at_end())
    {
        start = current;
        scan_token();
    }
    tokens.push_back(Token(TokenType::EOF_, "", "", line));
    return tokens;
}

void Scanner::scan_token()
{
    char c = advance();
    std::cout << "scanning " + std::string(1, c) << std::endl;

    switch (c)
    {
        case '(':
            add_token(TokenType::LeftParen);
            break;
        case ')':
            add_token(TokenType::RightParen);
            break;
        case '{':
            add_token(TokenType::LeftBrace);
            break;
        case '}':
            add_token(TokenType::RightBrace);
            break;
        case ',':
            add_token(TokenType::Comma);
            break;
        case '.':
            add_token(TokenType::Dot);
            break;
        case '-':
            add_token(TokenType::Minus);
            break;
        case '+':
            add_token(TokenType::Plus);
            break;
        case ';':
            add_token(TokenType::Semicolon);
            break;
        case '*':
            add_token(TokenType::Star);
            break;
        default:
            Lox::error(line, "Unexpected character.");
    }
}

bool Scanner::is_at_end()
{
    return current >= source.size();
}

char Scanner::advance()
{
    return source.at(current++);
}

void Scanner::add_token(TokenType type)
{
    add_token(type, "");
}

void Scanner::add_token(TokenType type, std::string literal)
{
    tokens.push_back(Token(type, source.substr(start, current), literal, line));
}
