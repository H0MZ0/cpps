#include "Serializer.hpp"

/* ===== Data ===== */
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

/* ===== Serializer ===== */
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) {(void)src;}
Serializer& Serializer::operator=(const Serializer& src) {(void)src; return *this;}
Serializer::~Serializer() {}

/* ===== Serializer methods ===== */
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
