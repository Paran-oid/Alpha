#include <iostream>

#include "Interpreter/Interpreter.h"

int main() {
    while(true) {
        try {
            std::cout << "alpha>";
            std::string text;
            std::cin >> text;
            if(text.empty()) continue;
            interpreter::Interpreter interpreter(text);
            std::string res = interpreter.expr();
            std::cout << res << std::endl;
        }
        catch(std::exception e) {
            std::cout << "Error:" << e.what() << std::endl;
        }
    }
}

