#include <vector>
#include <deque>
#include <cstdlib>
#include <stdexcept>
bool isStrNumber(char *str)
{
    int i = 0;
    if (!str[i])
        return false;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

std::vector<int> create_v(char **av)
{
    std::vector<int> v_num;
    for(int i = 1; av[i]; i++)
    {
        if (!isStrNumber(av[i]))
            throw std::runtime_error("The given parameter wasn't a number");
        int num = std::atoi(av[i]);
        if (num < 0)
            throw std::runtime_error("Negative int found.");
        v_num.push_back(num);
    }
    return v_num;
}


std::deque<int> create_d(char **av)
{
    std::deque<int> d_num;
    for(int i = 1; av[i]; i++)
    {
        if (!isStrNumber(av[i]))
            throw std::runtime_error("The given parameter wasn't a number");
        int num = std::atoi(av[i]);
        if (num < 0)
            throw std::runtime_error("Negative int found.");
        d_num.push_back(num);
    }
    return d_num;
}
