//
// Created by aziz on 10/2/24.
//

#ifndef ERROR_H
#define ERROR_H



class Error {
public:
    enum Type {
        PARSE,
        DIVIDE_BY_ZERO
    };
    static void throw_error(Type error_type);
};



#endif //ERROR_H
