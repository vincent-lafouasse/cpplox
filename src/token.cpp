#include "token.h"

#include <sstream>

Token::Token(TokenType type_,
             std::string lexeme_,
             /*Object literal_,*/ int line_) {
  type = type_;
  lexeme = lexeme_;
  // literal = literal_;
  line = line_;
}

std::string Token::to_string(void) {
  std::stringstream sstream;
  sstream << token_type_repr(type) << " " << lexeme /*<< " " << literal*/;
  return sstream.str();
}
