#include "RPN.hpp"

static double stringToDouble(const std::string& str) {
    std::istringstream ss(str);
    double result;
    ss >> result;
    return result;
}

RPN::RPN(){
}

RPN::~RPN(){
}

RPN::RPN(const RPN &other){
    if (this != &other){
        _stack = other._stack;
    }
}

RPN& RPN::operator=(const RPN &other){
    if (this != &other){
        _stack = other._stack;
    }
    return *this;
}

RPN::RPN(const std::string &str){
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ')
            continue;

        if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
            throw std::invalid_argument("Error: invalid character");

        if (isdigit(str[i])) {
            std::string number;
            while (isdigit(str[i])) {
                number += str[i];
                i++;
            }
            _stack.push(number);
        }

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (_stack.size() < 2)
                throw std::invalid_argument("Error: not enough operands");

            std::string op1 = _stack.top();
            _stack.pop();
            std::string op2 = _stack.top();
            _stack.pop();

            long double result;
            switch (str[i]) {
                case '+':
                    result = stringToDouble(op2) + stringToDouble(op1);
                    break;
                case '-':
                    result = stringToDouble(op2) - stringToDouble(op1);
                    break;
                case '*':
                    result = stringToDouble(op2) * stringToDouble(op1);
                    break;
                case '/':
                    result = stringToDouble(op2) / stringToDouble(op1);
                    break;
            }
            _stack.push(numberToString(result));
        }
    }
}

std::string RPN::getResult(){
    if (_stack.empty())
        throw std::invalid_argument("Error: not enough operands");
    if (_stack.size() > 1)
        throw std::invalid_argument("Error: missing operators");
    return _stack.top();
}
