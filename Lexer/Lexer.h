//
// Created by aziz on 10/1/24.
//

#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <Token.h>


namespace interpreter {
    class Lexer {
    public:
        Lexer(const std::string& text):m_text{text}, m_pos{0}, m_curr_char{text[0]}{}

        Token get_next_token();
        void advance();

        void skip_whitespace();
        std::string integer();
    private:
        int m_pos;
        char m_curr_char;
        std::string m_text;
    };

}

#endif //LEXER_H
