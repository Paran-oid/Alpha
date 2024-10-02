//
// Created by aziz on 10/2/24.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>

class Token {
public:
    enum Type {
        INTEGER,
        PLUS,
        MINUS,
        MULT,
        DIV,
        LPAREN,
        RPAREN,
        END
    };
    Token(const Type& type, const std::string& value): m_type{type}, m_value{value}
    {}

    Type type() const{return m_type;}
    std::string value() const{return m_value;}
private:
    Type m_type;
    std::string m_value;
};

#endif //TOKEN_H
