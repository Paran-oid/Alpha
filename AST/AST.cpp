//
// Created by aziz on 9/26/24.
//

#include "AST.h"
template <typename T>
T AST::parse(std::vector<Token> tokens)
{
    int i = 0;

    while(i < tokens.size())
    {
        T* ptr = &tokens[i];
        std::vector<int> nums{};
        std::string num {};

        if(ptr->type == NUMBER )
        {
            num += ptr->value;
        }

        if(ptr->type != NUMBER && num.length() > 0)
        {
            nums.push_back(std::stoi(num));
        }
        i++;
    }
}

