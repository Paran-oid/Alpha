
#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <vector>
#include <string>

//first we define our types
enum TokenType {NUMBER,PLUS,MINUS,STAR,SLASH,LPAREN,RPAREN,END};

//we create our token
struct Token
{
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& input);
#endif //TOKENIZER_H
