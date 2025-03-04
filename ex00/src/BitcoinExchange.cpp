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
}

bool isDateCorrect(std::string date)
{
    char *year = strtok((char *)date.c_str(), "-");
    char *month = strtok(NULL, "-");
    char *rest = strtok(NULL, "-");
    char *day = strtok(rest, ",");

    if (!year || !month || !rest || !day)
        return false;
    float f_month = strtofloat(month);
    if (f_month < 0 || f_month > 12)
        return false;
    if ((f_month == 1 || f_month == 3 || f_month == 5 || f_month == 7 || f_month == 7|| f_month == 8 || f_month == 10 || f_month == 12) && strtofloat(day) > 31)
        return false;
    else if (f_month != 2 && strtofloat(day) > 30)
        return false;
    else
    {
        float f_year = strtofloat(year);
        if ((((int)f_year % 4) == 0) && strtofloat(day) > 29)
            return false;
        else if(strtofloat(day) > 28)
            return false;
    }
    return true;
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
        if (amount > 1000)
        {
            std::cerr << "Error: Too big of a number." << std::endl;
            continue;
        }
        if (!isDateCorrect(date))
        {
            std::cerr << "Date is wrong." << std::endl;
            continue;
        }
        float valueByDate = getValueByDate(date);
        if (valueByDate < 0)
            std::cerr << "Date cannot be older than the oldest date on the data sheet." << std::endl;
        else
            std::cout << date << " => " << amount_str << " = " << std::fixed << std::setprecision(2) << valueByDate * amount << std::endl;
    }
}

//works only with ordered date tables
float searchClosestDate(std::map<std::string, float>& dataMap, std::string date)
{
    std::map<std::string, float>::iterator it = dataMap.begin();
    if (it->first.compare(date) > 0)
        return -1;
    for (; it != dataMap.end(); it++)
    {
        int diff = it->first.compare(date);
        if (diff > 0)
        {
            it--;
            return it->second;
        }
    }
    it--;
    return it->second;
}

float BitcoinExchange::getValueByDate(std::string date)
{
    //TO-DO: Add older than the data's oldest value handling.
    if (dateAndValue.count(date))
        return dateAndValue[date];
    else
        return searchClosestDate(dateAndValue, date);
}
