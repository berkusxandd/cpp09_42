#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : rawdata_path("./datas/data.csv")
{
    fillDateAndValue();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
   if (this != &rhs)
   {
        this->rawdata_path = rhs.rawdata_path;
        std::map<std::string, float>::const_iterator it = rhs.dateAndValue.begin();
        for (; it!=rhs.dateAndValue.end(); it++)
            this->dateAndValue[it->first] = it->second;
   }
   return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

const char* BitcoinExchange::RawDataFileCannotBeOpenedException::what() const throw()
{
    return ("Raw data file cannot be opened.");
}

void BitcoinExchange::printData()
{
    std::map<std::string, float>::iterator it = dateAndValue.begin();
    for (; it!=dateAndValue.end(); it++)
    {
        std::cout << "Date: " << it->first << " Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}

void BitcoinExchange::fillDateAndValue()
{
    std::string line;
    std::ifstream data(this->rawdata_path.c_str());
    if (!data.is_open())
        throw RawDataFileCannotBeOpenedException();
    getline(data,line);
    while(getline(data,line))
    {
        char *date = strtok((char *)line.c_str(), ",");
        char *value_str = strtok(NULL, ",");
        if (date != NULL && value_str != NULL)
            dateAndValue[std::string(date)] = strtofloat(value_str);
    }
    //printData();
}



void BitcoinExchange::startConversion(std::string input_file)
{
    std::ifstream input_data(input_file.c_str());
    std::string line;
    if (!input_data.is_open())
        throw RawDataFileCannotBeOpenedException();
    while (getline(input_data, line))
    {
        char *date = strtok((char *)line.c_str(), " | ");
        char *amount_str = strtok(NULL, " | ");
        if (!date || !amount_str)
        {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }
        float amount = strtofloat(amount_str);
        if (amount < 0)
        {
            std::cerr << "Error: Not a positive number." << std::endl;
            continue;
        }
        float valueByDate = getValueByDate(date);
        std::cout << date << " => " << amount_str << " = " << valueByDate * amount << std::endl;
    }
}

//works only with ordered date tables
float searchClosestDate(std::map<std::string, float>& dataMap, std::string date)
{
    std::map<std::string, float>::iterator it = dataMap.begin();
    for (; it != dataMap.end(); it++)
    {
        int diff = it->first.compare(date);
        if (diff > 0)
        {
            it--;
            return it->second;
        }
    }
    return -1;
}

float BitcoinExchange::getValueByDate(std::string date)
{
    //TO-DO: Add older than the data's oldest value handling.
    if (dateAndValue.count(date))
        return dateAndValue[date];
    else
        return searchClosestDate(dateAndValue, date);
}
