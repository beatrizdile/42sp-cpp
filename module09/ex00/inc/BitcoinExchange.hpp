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
        void readInputFile(const std::string &filename);
        std::map<std::string, int> _database;
    public:
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        BitcoinExchange(const std::string &filename);
};

#endif