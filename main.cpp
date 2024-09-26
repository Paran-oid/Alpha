#include <iostream>
#include <vector>
#include "tokenizer.h"

int main()
{
    std::string code = "1 + 1";
    std::vector<Token> tokens = tokenize(code);

    std::cout << "works!" << std::endl;
}
