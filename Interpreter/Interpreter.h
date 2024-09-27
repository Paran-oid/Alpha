//
// Created by aziz on 9/27/24.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <optional>
#include <string>

#include "../Token/Token.h"


class Interpreter {
public:
    explicit Interpreter(const std::string& text) : m_text(text) , m_pos(0){
        m_text = text;
    }
    Token get_next_token();
    void eat(TokenType type);
    std::string expr();
    void error();

private:
    Token m_curr_token = {END, "END"};
    std::string m_text;
    int m_pos;
};

#endif //INTERPRETER_H
