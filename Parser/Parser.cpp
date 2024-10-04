//
// Created by aziz on 10/2/24.
//


#include <Parser.h>

#include "Error.h"
#include "Expression.h"

void Parser::eat(Token::Type type) {
    if(m_curr_token.type() == type) {
        m_curr_token = m_lexer.next_token();
    }
    else {
        Error::throw_error(Error::PARSE);
    }
}



Expression* Parser::factor() {
    Token curr_token = m_curr_token;
    if(curr_token.type() == Token::INTEGER) {
        eat(Token::Type::INTEGER);
        return new Num(curr_token);
    }
    else if(curr_token.type() == Token::LPAREN) {
        eat(Token::Type::LPAREN);
        Expression* node = expr();
        eat(Token::Type::RPAREN);
        return node;
    }
    return nullptr;
}

Expression* Parser::term() {
    Expression* node = factor();
    while(m_curr_token.type() == Token::Type::DIV || m_curr_token.type() == Token::Type::MULT) {
        Token token = m_curr_token;
        if(token.type() == Token::MULT) {
            eat(Token::MULT);
        } else if(token.type() == Token::DIV) {
            eat(Token::DIV);
        }

        node = new BinOp(node, token, factor());
    }

    return node;
}


Expression* Parser::expr() {
    Expression* node = term();

    while(m_curr_token.type() == Token::PLUS || m_curr_token.type() == Token::MINUS) {
        Token token = m_curr_token;
        if(token.type() == Token::PLUS) {
            eat(Token::PLUS);
        } else if(token.type() == Token::MINUS) {
            eat(Token::MINUS);
        }
        node = new BinOp(node, token, term());
    }
    return node;
}

Expression* Parser::parse() {
    return expr();
}
