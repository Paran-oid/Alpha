#include <iostream>
#include <stdexcept>

#include "Interpreter/Interpreter.h"

int main()
{
    std::string text;

    while (true) {
        std::cout << "alpha> ";
        std::getline(std::cin, text);
        if (text.empty()) {
            continue;
        }

        try {
            Interpreter interpreter(text);
            std::string result = interpreter.expr();
            std::cout << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}

