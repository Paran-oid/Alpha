
#ifndef TOKEN_H
#define TOKEN_H
#include <stdexcept>
#include <string>

#include "TokenType.h"

class Token {
public:
    Token(const TokenType type, const std::string& value) {
        m_type = type;
        m_value = value;
    }

    [[nodiscard]] TokenType type() const{return m_type;}
    [[nodiscard]] std::string value() const {return m_value;}
    void setType(const TokenType& type) {m_type = type;}
    void setValue(const std::string& value) {m_value = value;}

private:
    TokenType m_type {};
    std::string m_value {};
};



#endif //TOKEN_H
