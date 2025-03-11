#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this == &rhs)
        std::cerr << "Copy overload failed because of same pointer usage" << std::endl;
    return (*this);
}

int RPN::calculate(const std::string &exp)
{
    std::istringstream iss(exp);
    std::stack<int> stack;
    std::string token;

    while (iss >> token) 
    {
        if (isdigit(token[0]) && token.size() == 1) 
        {
            stack.push(std::atoi(token.c_str()));
        } 
        else if (isOperator(token)) 
        {
            if (stack.size() < 2) 
                throw std::runtime_error("Error: Invalid expression");
            int b = stack.top(); 
            stack.pop();
            int a = stack.top(); 
            stack.pop();
            stack.push(applyOperation(a, b, token));
        } 
        else 
        {
            throw std::runtime_error("Error");
        }
    }
    if (stack.size() != 1) 
        throw std::runtime_error("Error: Invalid expression");
    return stack.top();
}