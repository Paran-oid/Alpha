//
// Created by aziz on 10/2/24.
//

#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "Lexer.h"

class Expression;

class Parser{
public:
    Parser(Lexer& lexer): m_lexer{lexer} {
        m_curr_token = m_lexer.next_token();
    }

    Expression* parse();
    Expression* expr();
    Expression* term();
    Expression* factor();

    void eat(Token::Type);
private:
    Lexer m_lexer;
    Token m_curr_token{Token::Type::END, "END"};
};



#endif //PARSER_H
