#include <string>
#include <sstream>
float strtofloat(std::string str)
{
    float f_val;
    std::stringstream ss(str);
    
    ss >> f_val;
    if (!ss.fail())
        return f_val;
    else
        return -1;
}