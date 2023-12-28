#include "Scanner.h"

#include <cctype>
#include <iostream>

#include "Lox.h"

std::vector<Token> Scanner::scan_tokens()
{
    while (!is_at_end())
    {
        start = current;
        scan_token();
    }
    tokens.push_back(Token(TokenType::EOF_, "", nullptr, line));
    return tokens;
}

void Scanner::scan_token()
{
    char c = advance();
    std::cout << "scanning " + std::string(1, c) << std::endl;

    using TT = TokenType;

    switch (c)
    {
            // parse single char tokens
        case '(':
            add_token(TT::LeftParen);
            break;
        case ')':
            add_token(TT::RightParen);
            break;
        case '{':
            add_token(TT::LeftBrace);
            break;
        case '}':
            add_token(TT::RightBrace);
            break;
        case ',':
            add_token(TT::Comma);
            break;
        case '.':
            add_token(TT::Dot);
            break;
        case '-':
            add_token(TT::Minus);
            break;
        case '+':
            add_token(TT::Plus);
            break;
        case ';':
            add_token(TT::Semicolon);
            break;
        case '*':
            add_token(TT::Star);
            break;
            // parse two char tokens
        case '!':
            add_token(match('=') ? TT::BangEqual : TT::Bang);
            break;
        case '=':
            add_token(match('=') ? TT::EqualEqual : TT::Equal);
            break;
        case '<':
            add_token(match('=') ? TT::LessEqual : TT::Less);
            break;
        case '>':
            add_token(match('=') ? TT::GreaterEqual : TT::Greater);
            break;
        // parse comments by ignoring everything until newline
        case '/':
            if (match('/'))
            {
                while (peek() != '\n' && !is_at_end())
                    advance();
            }
            else
            {
                add_token(TT::Slash);
            }
            break;
        // ignore whitespace
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        // parse strings
        case '"':
            scan_string();
            break;
        default:
            if (std::isdigit(c))
            {
                scan_number();
            }
            else
            {
                Lox::error(line, "Unexpected character.");
            }
    }
}

void Scanner::scan_string()
{
    while (peek() != '"' && !is_at_end())
    {
        if (peek() == '\n')
            line++;
        advance();
    }
    if (is_at_end())
    {
        Lox::error(line, "Unterminated string.");
    }
    // advance past closing "
    advance();

    Literal value = source.substr(start + 1, current - start - 2);
    add_token(TokenType::String, value);
}

void Scanner::scan_number() {}

void Scanner::add_token(TokenType type)
{
    add_token(type, nullptr);
}

void Scanner::add_token(TokenType type, Literal literal)
{
    tokens.push_back(
        Token(type, source.substr(start, current - start), literal, line));
}

bool Scanner::is_at_end() const
{
    return current >= source.size();
}

char Scanner::advance()
{
    return source.at(current++);
}

bool Scanner::match(char expected)
{
    if (is_at_end())
        return false;
    if (source.at(current) != expected)
        return false;
    current++;
    return true;
}

char Scanner::peek() const
{
    if (is_at_end())
        return '\0';
    return source.at(current);
}
