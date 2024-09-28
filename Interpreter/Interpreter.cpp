//
// Created by aziz on 9/27/24.
//

#include "Interpreter.h"

void Interpreter::error() {
    throw std::runtime_error("error parsing");
}

void Interpreter::advance() {
    ++m_pos;
    if(m_pos > m_text.length()) {
        m_curr_char = '\0';
    }
    else {
        m_curr_char = m_text[m_pos];
    }
}

void Interpreter::skip_whitespace() {
    while(std::isspace(m_curr_char) && m_curr_char != '\0') {
        advance();
    }
}

int Interpreter::integer() {
    std::string result;
    while(m_curr_char != '\0' && std::isdigit(m_curr_char)) {
        result += m_curr_char;
        advance();
    }
    return std::stoi(result);
}


Token Interpreter::get_next_token() {
    while(m_curr_char != '\0') {
        if (std::isspace(m_curr_char)) {
            skip_whitespace();
            continue;
        }
        else if (std::isdigit(m_curr_char)) {
            return Token{INTEGER, std::to_string(integer())};
        }
        else if (m_curr_char == '+') {
            advance();
            return Token{PLUS, "+"};
        }
        else if (m_curr_char == '-') {
            advance();
            return Token{MINUS, "-"};
        }
        else if (m_curr_char == '*') {
            advance();
            return Token{MULTI, "*"};
        }
        else if (m_curr_char == '/') {
            advance();
            return Token{DIVIDE, "/"};
        }
        else {
            error();
        }
    }
    return Token{END, ""};
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
    bool isRunning = true;
    auto result = 0;

    m_curr_token = get_next_token();
    Token left = m_curr_token;
    eat(INTEGER);

    while(true) {

        Token op = m_curr_token;
        if(m_curr_token.type() == PLUS) eat(PLUS);
        else if(m_curr_token.type() == MINUS) eat(MINUS);
        else if(m_curr_token.type() == MULTI) eat(MULTI);
        else if(m_curr_token.type() == DIVIDE) eat(DIVIDE);
        else break;

        Token right = m_curr_token;
        eat(INTEGER);


        const auto leftval = std::stod(left.value());
        const auto rightval = std::stoi(right.value());

        switch(op.type()) {
            case PLUS:
                result = leftval + rightval;
            break;
            case MINUS:
                result = leftval - rightval;
            break;
            case MULTI:
                result = leftval * rightval;
            break;
            case DIVIDE:
                result = leftval / rightval;
            break;
            default: ;
        }

        left.setValue(std::to_string(result));
        right.setValue("");
    }

    return std::to_string(result);
}

