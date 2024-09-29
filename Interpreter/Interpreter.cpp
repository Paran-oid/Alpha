//
// Created by aziz on 9/27/24.
//

#include "Interpreter.h"

#include <algorithm>
#include <vector>

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

std::string Interpreter::term() {
    Token token = m_curr_token;
    eat(INTEGER);
    return token.value();
}


std::string Interpreter::expr() {
    m_curr_token = get_next_token();
    auto result = term();
    int val = std::stoi(result);

    std::vector<TokenType> operators{PLUS, MINUS, MULTI, DIVIDE};
    while(std::find(operators.begin(), operators.end(), m_curr_token.type()) != operators.end()) {
        if(m_curr_token.type() == PLUS) {
            eat(PLUS);
            val += std::stoi(term());
        }
        else if(m_curr_token.type() == MINUS) {
            eat(MINUS);
            val -= std::stoi(term());
        }
        else if(m_curr_token.type() == MULTI) {
            eat(MULTI);
            val *= std::stoi(term());
        }
        else if(m_curr_token.type() == DIVIDE) {
            eat(DIVIDE);
            val /= std::stoi(term());
        } else break;
    }

    result = std::to_string(val);
    return result;
}

