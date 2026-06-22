#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(char c);
    int  calculate(int a, int b, char op);

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void evaluate(const std::string &expr);
};

#endif