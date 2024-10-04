//
// Created by aziz on 10/4/24.
//

#include "Interpreter.h"

#include <stdexcept>
#include "Parser.h"
#include "Expression.h"
#include <iostream>


int Interpreter::visit(Expression* node) {
    return node->accept(*this);
}

int Interpreter::visit_BinOp(BinOp* node) {
    if (node->op().type() == Token::PLUS) {
        return visit(node->left()) + visit(node->right());
    } else if (node->op().type() == Token::MINUS) {
        return visit(node->left()) - visit(node->right());
    } else if (node->op().type() == Token::MULT) {
        return visit(node->left()) * visit(node->right());
    } else if (node->op().type() == Token::DIV) {
        int right_val = visit(node->right());
        if (right_val == 0) {
            throw std::runtime_error("Division by zero error");
        }
        return visit(node->left()) / right_val;
    }

    throw std::runtime_error("Unknown operator");
}

int Interpreter::visit_Num(Num* node) {
    return std::stoi(node->value());
}

std::string Interpreter::interpret() {
    Expression* tree = m_parser.parse();
    return std::to_string(visit(tree));
}
