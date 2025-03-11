#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cstdlib>

bool isOperator(const std::string &token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int applyOperation(int a, int b, const std::string &op) 
{
    if (op == "+") 
        return a + b;
    if (op == "-") 
        return a - b;
    if (op == "*") 
        return a * b;
    if (op == "/") 
    {
        if (b == 0) 
            throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Invalid operator");
}
