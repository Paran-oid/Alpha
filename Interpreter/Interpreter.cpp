//
// Created by aziz on 10/2/24.
//

#include "Interpreter.h"

#include <complex>

#include "../Error/Error.h"

void Interpreter::eat(Token::Type type) {
    if(m_curr_token.type() == type) {
        m_curr_token = m_lexer.next_token();
    }
    else {
        Error::throw_error(Error::PARSE);
    }
}



auto Interpreter::factor() {
    if(m_curr_token.type() == Token::INTEGER) {
        Token curr_token = m_curr_token;
        eat(Token::Type::INTEGER);
        return curr_token.value();
    }
    else if(m_curr_token.type() == Token::LPAREN) {
        eat(Token::Type::LPAREN);
        auto result = expr();
        eat(Token::Type::RPAREN);
        return result;
    }
}

auto Interpreter::term() {
    auto result = std::stoi(factor());
    while(m_curr_token.type() == Token::Type::DIV || m_curr_token.type() == Token::Type::MULT) {
        Token token = m_curr_token;
        if(token.type() == Token::MULT) {
            eat(Token::MULT);
            result *= std::stoi(factor());
        }
        if(token.type() == Token::DIV) {
            eat(Token::DIV);
            result /= std::stoi(factor());
        }
    }
    return std::to_string(result);
}


std::string Interpreter::expr() {
    auto result = std::stoi(term());

    while(m_curr_token.type() == Token::PLUS || m_curr_token.type() == Token::MINUS) {
        Token token = m_curr_token;
        if(token.type() == Token::PLUS) {
            eat(Token::PLUS);
            result += std::stoi(term());
        }
        if(token.type() == Token::MINUS) {
            eat(Token::MINUS);
            result -= std::stoi(term());
        }
    }

    return std::to_string(result);
}
