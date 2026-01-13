#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
    int n;
    std::string s;

};

class Serializer {
    private:
        Serializer();  // Non-instantiable
        Serializer(Serializer const & src);
        Serializer & operator=(Serializer const & src);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif