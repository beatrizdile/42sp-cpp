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
        void calculateExchange(const std::string& targetDate, long double value);
        std::map<std::string, long double> _database;
    public:
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        BitcoinExchange(const std::string &filename);
};

#endif