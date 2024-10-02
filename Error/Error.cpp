//
// Created by aziz on 10/2/24.
//

#include "Error.h"

#include <stdexcept>

void Error::throw_error(Type error_type) {
    switch(error_type) {
        case Type::PARSE:
            throw std::runtime_error("Parsing error.");
        case Type::DIVIDE_BY_ZERO:
            throw std::runtime_error("Can't divide by zero.");
    }
}
