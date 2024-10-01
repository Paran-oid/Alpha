//
// Created by aziz on 10/1/24.
//

#include "Error.h"

#include <stdexcept>

void Error::throw_error(ErrorTypes error_type) {
    switch(error_type) {
        case ErrorTypes::ERR_DIVIDE_BY_ZERO:
            throw std::runtime_error("Can't divide by zero!");
            break;
        case ErrorTypes::ERR_PARSING:
            throw std::runtime_error("Parsing error");
            break;
    }
}
