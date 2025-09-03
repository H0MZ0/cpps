#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
        std::string const&  getType();
        void                setType(std::string n);
};


#endif