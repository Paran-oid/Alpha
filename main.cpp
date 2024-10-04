#include <Interpreter.h>
#include <iostream>

#include "Parser.h"
#include "Lexer.h"

int main() {
    try {
        while(true) {
            std::cout << "alpha>";

            std::string input;
            std::getline(std::cin, input);
            if(input.empty()) continue;
            if(input == "exit") break;

            Lexer lexer(input);
            Parser parser(lexer);
            Interpreter interpreter(parser);
            std::string result = interpreter.interpret();
            std::cout << result << std::endl;
        }
        std::cout << "alpha exited with exit code 0";
        return 0;
    } catch (std::exception e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
