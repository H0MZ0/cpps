#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
}
RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::calculate(int a, int b, char op, int &result) {
    long long res = 0;
    
    if (op == '+') res = (long long)a + b;
    else if (op == '-') res = (long long)a - b;
    else if (op == '*') res = (long long)a * b;
    else if (op == '/') {
        if (b == 0) return false;
        res = (long long)a / b;
    }
    
    if (res > 2147483647 || res < -2147483648)
        return false;
        
    result = static_cast<int>(res);
    return true;
}

void RPN::evaluate(const std::string &expr) {
    std::stringstream ss(expr);
    std::string token;

    if (expr.find_first_not_of(" \t") == std::string::npos) {
        std::cerr << "Error" << std::endl;
        return;
    }

    while (ss >> token) {
        if (token.length() != 1) {
            std::cerr << "Error" << std::endl;
            return;
        }

        char c = token[0];

        if (isdigit(c)) {
            _stack.push(c - '0');
        } 
        else if (isOperator(c)) {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            
            int result = 0;
            if (!calculate(a, b, c, result)) {
                std::cerr << "Error" << std::endl;
                return;
            }
            _stack.push(result);
        } 
        else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
    } else {
        std::cout << _stack.top() << std::endl;
    }
}
