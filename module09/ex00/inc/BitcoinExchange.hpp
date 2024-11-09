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
        void generateBitcoinExchange(const std::string &filename);
        void calculateExchange(const std::map<std::string, int>& dateMap, const std::string& targetDate, double value);
        std::map<std::string, int> _database;
    public:
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        BitcoinExchange(const std::string &filename);
};

#endif