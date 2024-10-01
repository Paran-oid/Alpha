//
// Created by aziz on 9/30/24.
//

#include "Interpreter.h"

#include <iostream>

namespace interpreter {

    //CHECK TYPES
    void Interpreter::skip_whitespace() {
        while(std::isspace(m_curr_char) && m_curr_char != '\0') advance();
    }
    std::string Interpreter::integer() {
        std::string result;
        while(std::isdigit(m_curr_char) && m_curr_char != '\0') {
            result+=m_curr_char;
            advance();
        }
        return result;
    }

    //UPDATE VALUES
    void Interpreter::advance() {
        m_pos++;
        if(m_pos > m_text.length()) {
            m_curr_char = '\0';
        }
        else {
            m_curr_char = m_text[m_pos];
        }
    }
    void Interpreter::eat(TokenType type) {
        if(m_current_token.type == type) {
            m_current_token = next_token();
        }
    }

    //LEXER
    Token Interpreter::next_token() {
        while(m_curr_char != '\0') {
            if(std::isdigit(m_curr_char)) {
                return {TokenType::INTEGER, integer()};
            }
            if(std::isspace(m_curr_char)) {
                skip_whitespace();
                continue;
            }
            if(m_curr_char == '+') {
                advance();
                return {TokenType::PLUS, "+"};
            }
            if(m_curr_char == '-') {
                advance();
                return {TokenType::MINUS, "-"};
            }
            if(m_curr_char == '*') {
                advance();
                return {TokenType::MULTIP, "*"};
            }
            if(m_curr_char == '/') {
                advance();
                return {TokenType::DIVID, "/"};
            }
            error();

        }
        return {TokenType::END, "END"};
    }

    //OPERATIONS
    std::string Interpreter::term() {
        Token token = m_current_token;
        eat(TokenType::INTEGER);
        return token.value;
    }

    //INTERPRETER
    std::string Interpreter::expr() {
        m_current_token = next_token();
        int result = std::stoi(term());
        while(m_current_token.type == TokenType::PLUS || m_current_token.type == TokenType::MINUS) {
            Token token = m_current_token;
            if(token.type == TokenType::PLUS) {
                eat(TokenType::PLUS);
                result += std::stoi(term());
            }
            else if(token.type == TokenType::MINUS) {
                eat(TokenType::MINUS);
                result -= std::stoi(term());
            }
        }
        return std::to_string(result);
    }

    void Interpreter::error() {
        throw std::runtime_error("Parsing error");
    }

}
