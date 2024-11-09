#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <sys/stat.h>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        std::string findClosestDate(const std::map<std::string, int>& dateMap, const std::string& targetDate);
        void generateBitcoinExchange(const std::string &filename);
        std::map<std::string, int> _database;
    public:
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        BitcoinExchange(const std::string &filename);
};

#endif