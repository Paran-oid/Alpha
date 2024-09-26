//
// Created by aziz on 9/26/24.
//

#ifndef AST_H
#define AST_H
#include <tokenizer.h>


class AST {
public:
    template<typename T>
    T parse(std::vector<Token> tokens);

private:
    std::string content;
};



#endif //AST_H
