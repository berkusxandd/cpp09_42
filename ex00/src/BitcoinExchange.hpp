#ifndef BTC_EXCHANGE
#define BTC_EXCHANGE

#include <iostream>
#include <cstring>
#include <map>
#include <fstream>
#include <stdexcept>
#include <iomanip>
class BitcoinExchange
{
    private:
        std::string rawdata_path;
        std::map<std::string,float> dateAndValue;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        ~BitcoinExchange();

        void fillDateAndValue();
        //TO-DO: delete print data (debug only)
        void printData();
        void startConversion(std::string input_file);
        float getValueByDate(std::string date);
    class RawDataFileCannotBeOpenedException : public std::exception
    {
        virtual const char* what() const throw();
    };
};

// -- UTILS --
float strtofloat(std::string str);
#endif