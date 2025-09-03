#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>

class Test{

    private:
    std::string name;
    int         age;

    public:
    Test();
    ~Test();
    void display(std::string name);
};

#endif