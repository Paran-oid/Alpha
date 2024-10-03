//
// Created by aziz on 10/2/24.
//

#include "Lexer.h"

#include "Error.h"

void Lexer::advance() {
    m_pos++;
    if(m_pos >= m_text.length()) {
        m_curr_char = '\0';
    }
    else {
        m_curr_char = m_text[m_pos];
    }
}

void Lexer::is_whitespace() {
    while(std::isspace(m_curr_char) && m_curr_char!= '\0') {
        advance();
    }
}

std::string Lexer::integer() {
    std::string result;
    while(std::isdigit(m_curr_char) && m_curr_char!='\0'){
        result += m_curr_char;
        advance();
    }
    return result;
}

Token Lexer::next_token() {
    while (m_curr_char != '\0') {
        if(std::isdigit(m_curr_char)) {
            return Token{Token::Type::INTEGER, integer()};
        }
        if(isspace(m_curr_char)) {
            is_whitespace();
            continue;
        }

        switch (m_curr_char) {
            case '+':
                advance();
                return {Token::Type::PLUS, "+"};
                break;
            case '-':
                advance();
                return {Token::Type::MINUS, "-"};
                break;
            case '*':
                advance();
                return {Token::Type::MULT, "*"};
                break;
            case '/':
                advance();
                return {Token::Type::DIV, "/"};
                break;
            case '(':
                advance();
                return {Token::Type::LPAREN, "("};
                break;
            case ')':
                advance();
                return {Token::Type::RPAREN, ")"};
                break;
            default:
                Error::throw_error(Error::Type::PARSE);
                break;
        }
    }
    return Token{Token::Type::END, "END"};
}