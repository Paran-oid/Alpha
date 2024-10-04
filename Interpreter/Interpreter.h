//
// Created by aziz on 10/4/24.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <Parser.h>
#include <string>

class Num;
class BinOp;

class Interpreter {
public:
    Interpreter(const Parser& parser) : m_parser{parser} {}

    std::string interpret();

    int visit(Expression* node);
    int visit_BinOp(BinOp* node);
    int visit_Num(Num* node);

private:
    Parser m_parser;
};

#endif //INTERPRETER_H
