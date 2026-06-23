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

int RPN::calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            std::cerr << "Error: division by zero" << std::endl;
            exit(1);
        }
        return a / b;
    }
    return 0;
}

void RPN::evaluate(const std::string &expr) {
    std::stringstream ss(expr);
    std::string token;

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
            
            _stack.push(calculate(a, b, c));
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