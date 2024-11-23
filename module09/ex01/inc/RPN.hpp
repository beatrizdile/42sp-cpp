#ifndef RPN_HPP
#define RPN_HPP

#include <sys/stat.h>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <string>

class RPN
{
    private:
        RPN();
        std::stack<std::string> _stack;
    public:
        ~RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        RPN(const std::string &str);
        std::string getResult();
};

template<typename T>
std::string numberToString(T value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

#endif