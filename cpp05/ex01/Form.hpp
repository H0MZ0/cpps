#pragma once

#include <iostream>
#include <exception>

class Form{
    private:
    const std::string name;
    bool sig;
    const int sign;
    const int execute;

    public:
    Form();
    Form(std::string name, int sign, int execute);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    int getSign() const;
    int getExecute() const;
};