#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <sys/stat.h>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <map>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        bool isValidFile(const char* path);
        std::string findClosestDate(const std::map<std::string, int>& dateMap, const std::string& targetDate);
        void readData(const std::string &filename);
    public:
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        BitcoinExchange(const std::string &filename);
};

#endif