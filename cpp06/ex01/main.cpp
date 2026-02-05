#include "Serializer.hpp"

int main() {
    Data original;
    original.n = 42;
    original.s = "Hello";
    
    Data* ptr = &original;
    
    uintptr_t raw = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(raw);
    
    if (ptr == deserialized)
        std::cout << "Success!" << std::endl;
    
    std::cout << "n: " << deserialized->n << std::endl;
    std::cout << "s: " << deserialized->s << std::endl;
    
    return 0;
}