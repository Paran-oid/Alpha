//
// Created by aziz on 9/30/24.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>

#include "TokenType.h"

struct Token {
        TokenType type;
        std::string value;
    };
#endif //TOKEN_H
