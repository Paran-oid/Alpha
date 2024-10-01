//
// Created by aziz on 9/30/24.
//

#include "Interpreter.h"

#include <iostream>

#include "Error.h"

namespace interpreter {
    //UPDATE VALUES
    void Interpreter::eat(TokenType type) {
        if(m_current_token.type == type) {
            m_current_token = m_lexer.get_next_token();
        } else {
            Error::throw_error(ERR_PARSING);
        }
    }

    //OPERATIONS
    std::string Interpreter::factor() {
        Token token = m_current_token;
        eat(TokenType::INTEGER);
        return token.value;
    }
    std::string Interpreter::term() {

        int result = std::stoi(factor());

        while(m_current_token.type == TokenType::MULTIP || m_current_token.type == TokenType::DIVID) {
            Token token = m_current_token;
            if(token.type == TokenType::MULTIP) {
                eat(TokenType::MULTIP);
                result *= std::stoi(factor());
            }
            else if(token.type == TokenType::DIVID) {
                eat(TokenType::DIVID);
                int temp = std::stoi(factor());
                if(temp == 0) {
                    Error::throw_error(ErrorTypes::ERR_DIVIDE_BY_ZERO);
                }
                else {
                    result /= temp;
                }
            }
        }

        return std::to_string(result);
    }


    //INTERPRETER
    std::string Interpreter::expr() {
        m_current_token = m_lexer.get_next_token();

        int result = std::stoi(term());

        while(m_current_token.type == TokenType::PLUS
            || m_current_token.type == TokenType::MINUS) {
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


}
