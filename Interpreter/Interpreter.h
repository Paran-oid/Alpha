//
// Created by aziz on 9/30/24.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>

#include "../Token/Token.h"

namespace interpreter {
    class Interpreter {
    public:
        Interpreter(const std::string &text):
            m_text{text}, m_pos{0}, m_curr_char{text[0]}
        {}


        Token next_token();
        std::string expr();

        void skip_whitespace();
        std::string integer();
        std::string term();

        void eat(TokenType type);
        void advance();
        static void error();


    private:
        char m_curr_char{};
        std::string m_text{};
        Token m_current_token{TokenType::END, "END"};
        int m_pos;
    };

}

#endif //INTERPRETER_H
