#include <iostream>

#include "Interpreter/Interpreter.h"

int main() {
    while(true) {
        try {
            std::cout << "alpha>";
            std::string text;
            std::cin >> text;
            if(text.empty()) continue;

            interpreter::Lexer lexer(text);
            interpreter::Interpreter interpreter(lexer);

            std::string res = interpreter.expr();
            std::cout << res << std::endl;
        }
        catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

