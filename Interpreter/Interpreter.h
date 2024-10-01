//
// Created by aziz on 9/30/24.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>

#include "Token.h"
#include "../Lexer/Lexer.h"

namespace interpreter {
    class Interpreter {
    public:
        explicit Interpreter(Lexer& lexer): m_lexer{lexer}{
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
