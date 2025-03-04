#include <string>
#include <sstream>
#include <iostream>
float strtofloat(std::string str)
{
    float f_val;
    std::stringstream ss(str);
    
    ss >> f_val;
    if (!ss.fail())
        return f_val;
    else
    {
        std::cerr << "Error: cannot convert to float." << std::endl;
        return -1;
    }
}