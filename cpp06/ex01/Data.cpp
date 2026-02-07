#include "Data.hpp"

Data::Data() {}
Data::Data(const Data& other) : n(other.n), s(other.s) {}
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        n = other.n;
        s = other.s;
    }
    return *this;
}
Data::~Data() {}
