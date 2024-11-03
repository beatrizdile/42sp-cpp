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
    public:
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &other);
        BitcoinExchange(const std::string &filename);
        void readData(const std::string &filename);
};

#endif