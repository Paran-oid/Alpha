//
// Created by aziz on 10/1/24.
//

#include "Lexer.h"

#include <Error.h>
#include <TokenType.h>

namespace interpreter {
    void Lexer::skip_whitespace() {
        while(std::isspace(m_curr_char) && m_curr_char != '\0') {
            advance();
        }
    }
    void Lexer::advance() {
        m_pos++;
        if(m_pos >= m_text.length()) {
            m_curr_char = '\0';
        }
        else {
            m_curr_char = m_text[m_pos];
        }
    }

    std::string Lexer::integer() {
        std::string result;
        while(std::isdigit(m_curr_char) && m_curr_char != '\0') {
            result += m_curr_char;
            advance();
        }
        return result;
    }

    Token Lexer::get_next_token() {
        while(m_curr_char != '\0') {
            if(std::isdigit(m_curr_char)) {
                return {TokenType::INTEGER, integer()};
            }
            if(std::isspace(m_curr_char)) {
                skip_whitespace();
                continue;
            }
            switch (m_curr_char) {
                case '+': advance(); return {TokenType::PLUS, "+"};
                case '-': advance(); return {TokenType::MINUS, "-"};
                case '*': advance(); return {TokenType::MULTIP, "*"};
                case '/': advance(); return {TokenType::DIVID, "/"};
                default: Error::throw_error(ERR_PARSING);
            }
        }
        return {TokenType::END, "END"};
    }



}

