//
// Created by aziz on 10/2/24.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Lexer.h"


class Interpreter{
public:
    Interpreter(Lexer& lexer): m_lexer{lexer} {
        m_curr_token = m_lexer.next_token();
    }

    std::string expr();
    auto term();
    auto factor();

    void eat(Token::Type);
private:
    Lexer m_lexer;
    Token m_curr_token{Token::Type::END, "END"};
};



#endif //INTERPRETER_H
