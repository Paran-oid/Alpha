//
// Created by aziz on 9/30/24.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>

#include "Token.h"
#include "Lexer.h"

namespace interpreter {
    class Interpreter {
    public:
        explicit Interpreter(interpreter::Lexer& lexer): m_lexer{lexer}{
            m_current_token = m_lexer.get_next_token();
        }

        std::string expr();

        std::string term();
        std::string factor();

        void eat(TokenType type);

    private:
        Lexer m_lexer;
        Token m_current_token{};
    };

}

#endif //INTERPRETER_H
