//
// Created by aziz on 10/4/24.
//

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <Interpreter.h>
#include "Token.h"


class Expression {
public:
    virtual ~Expression() = default;
    virtual int accept(Interpreter& visitor) = 0;
};

class BinOp : public Expression {
public:
    BinOp(Expression* left, Token op ,Expression*right)
    : m_left{left}, m_op{op}, m_token{op}, m_right{right}
    {}

    Expression* left() const{return m_left;}
    Expression* right() const{return m_right;}
    Token op() const{return m_op;}
    Token token() const{return m_token;}


    int accept(Interpreter& visitor) override {
        return visitor.visit_BinOp(this);
    }


private:
    Expression* m_left;
    Token m_op;
    Token m_token;
    Expression* m_right;
};

class Num : public Expression{
public:
    Num(Token token)
        : m_token{token}, m_value{token.value()}
    {}

    std::string& value(){return m_value;}

    int accept(Interpreter& visitor) override {
        return visitor.visit_Num(this);
    }



private:
    Token m_token;
    std::string m_value;
};


#endif //EXPRESSION_H
