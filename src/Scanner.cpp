#include "Scanner.h"

#include <cctype>
#include <iostream>

#include "Lox.h"

static bool is_digit(char c);
static bool is_alnum(char c);

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
            if (is_digit(c))
            {
                scan_number();
            }
            else if (is_alnum(c))
            {
                scan_identifier();
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

    std::string value = source.substr(start + 1, current - start - 2);
    add_token(TokenType::String, value);
}

void Scanner::scan_number()
{
    while (is_digit(peek()))
        advance();
    if (peek() == '.' && is_digit(peek_next()))
    {
        advance();
        while (is_digit(peek()))
            advance();
    }

    std::string s = source.substr(start, current - start);
    add_token(TokenType::Number, std::stod(s));
}

void Scanner::scan_identifier()
{
    while (is_alnum(peek()))
        advance();

    std::string value = source.substr(start, current - start);

	TokenType type = get_keyword(value).value_or(TokenType::Identifier);

    add_token(type, value);
}

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

char Scanner::peek_next() const
{
    if (current + 1 >= source.size())
        return '\0';
    return source.at(current + 1);
}

static bool is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

static bool is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

static bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

static bool is_alpha(char c)
{
    return is_upper(c) || is_lower(c) || (c == '_');
}

static bool is_alnum(char c)
{
    return is_digit(c) || is_alpha(c);
}
