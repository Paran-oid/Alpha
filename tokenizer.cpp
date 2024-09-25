#include <iostream>
#include <vector>
#include <string>
#include <cctype>


//first we define our types
enum TokenType {NUMBER,PLUS,MINUS,STAR,SLASH,LPAREN,RPAREN,END};


//we create our token
struct Token
{
    TokenType type;
    std::string value;
};

//we initiate our tokenize method
std::vector<Token> tokenize(const std::string& input)
{
    std::vector<Token> tokens;
    size_t i = 0;

    while(i < input.length())
    {
        if(std::isdigit(input[i]))
        {
            std::string num;
            while(isdigit(input[i]) && i < input.length())
            {
                num += input[i];
                i++;
            }
            tokens.push_back({NUMBER, num});
        }
        switch(input[i])
        {
        case '+':
            tokens.push_back({PLUS, "+"});
            i++;
            break;

        case '-':
            tokens.push_back({MINUS, "-"});
            i++;
            break;


        case '*':
            tokens.push_back({STAR, "*"});
            i++;
            break;

        case '/':
            tokens.push_back({SLASH, "/"});
            i++;
            break;


        case '(':
            tokens.push_back({LPAREN, "("});
            i++;
            break;

        case ')':
            tokens.push_back({RPAREN, ")"});
            i++;
            break;
        default:
            i++;
        }
    }

    tokens.push_back({END, ""});
    return tokens;
}