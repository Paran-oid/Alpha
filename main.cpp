#include <iostream>

#include "Interpreter/Interpreter.h"
#include "Lexer/Lexer.h"

int main() {
    try {
        while(true) {
            std::cout << "alpha>";

            std::string input;
            std::getline(std::cin, input);
            if(input.empty()) continue;
            if(input == "exit") break;

            Lexer lexer(input);
            Interpreter interpreter(lexer);
            std::string result = interpreter.expr();

            std::cout << result << std::endl;
        }
        std::cout << "alpha exited with exit code 0";
        return 0;
    } catch (std::exception e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
