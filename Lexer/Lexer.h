//
// Created by aziz on 10/2/24.
//

#ifndef LEXER_H
#define LEXER_H
#include <string>

#include "../Token/Token.h"


class Lexer {
public:
    explicit Lexer(const std::string& text): m_text{text}, m_pos{0}, m_curr_char{text[0]}
    {}

    Token next_token();

    void is_whitespace();
    std::string integer();

    void advance();

private:
    int m_pos;
    char m_curr_char;
    std::string m_text;
};



#endif //LEXER_H
