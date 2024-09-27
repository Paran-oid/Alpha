//
// Created by aziz on 9/27/24.
//

#include "Interpreter.h"

void Interpreter::error() {
    throw std::runtime_error("error parsing");
}

Token Interpreter::get_next_token() {
    if(m_pos > m_text.length() - 1) {
        return Token{TokenType::END, "END"};
    }

    char curr_char =  m_text[m_pos];
    if(std::isdigit(curr_char)) {
        Token token {TokenType::INTEGER, std::to_string(curr_char - '0')};
        ++m_pos;
        return token;
    }

    if(std::isspace(curr_char)) {
        ++m_pos;
        return get_next_token();
    }

    if(curr_char == '+') {
        Token token = {TokenType::PLUS, "+"};
        ++m_pos;
        return token;
    }
    error();
}

void Interpreter::eat(TokenType type) {
    if(m_curr_token.type() == type) {
        m_curr_token = get_next_token();
    }
    else {
        error();
    }
}


std::string Interpreter::expr() {
    m_curr_token = get_next_token();

    Token left = m_curr_token;
    eat(INTEGER);
    while(m_curr_token.type() == INTEGER) {
        left.setValue(left.value() + m_curr_token.value());
        eat(INTEGER);
    }

    Token op = m_curr_token;
    eat(PLUS);

    Token right = m_curr_token;
    eat(INTEGER);
    while (m_curr_token.type() == INTEGER) {
        right.setValue(right.value() + m_curr_token.value());
        eat(INTEGER);
    }


    std::string result = std::to_string(std::stoi(left.value()) + std::stoi(right.value()));
    return result;
}

