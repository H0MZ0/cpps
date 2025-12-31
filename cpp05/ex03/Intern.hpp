#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class Intern{
    private:


    public:
    Intern();
    Intern(const std::string& name, int grade);
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    void makeForm(std::string name, std::string form);


};


#endif