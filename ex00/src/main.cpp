#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    //TO-DO: check args.
    if (ac < 2)
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 0;
    }
    BitcoinExchange BtcXc;
    BtcXc.startConversion(av[1]);
}