#include "tokenizer.cpp"

struct ASTNode {
    Token token;
    ASTNode* left = nullptr;
    ASTNode* right = nullptr;

    ASTNode(const Token& token): token(token) {}
};

class Parse
{
private:
    std::vector<Token> tokens;
    size_t current = 0;

    Token peak(){return tokens[current];}
    Token consume(){return tokens[current++];}

    ASTNode* expression(){return addition();}

    ASTNode* addition;
};
