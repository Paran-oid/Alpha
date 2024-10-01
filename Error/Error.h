//
// Created by aziz on 10/1/24.
//

#ifndef ERROR_H
#define ERROR_H


enum ErrorTypes {
    ERR_PARSING,
    ERR_DIVIDE_BY_ZERO
};

class Error {
public:
    static void throw_error(ErrorTypes error_type);
};



#endif //ERROR_H
