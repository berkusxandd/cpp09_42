#include <iostream>

#include "RPN.hpp"
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments" << std::endl;
        return 1;
    }

    RPN rpn;
    try 
    {
        int result = rpn.calculate(argv[1]);
        std::cout << result << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}