#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TEST 1: Basic Creation and Polymorphism ===" << std::endl;
    Animal a;
    // AAnimal a; //not work
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\nTesting polymorphic behavior:" << std::endl;
    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    std::cout << cat->getType() << " says: ";
    cat->makeSound();
    
    std::cout << "\nDeleting animals..." << std::endl;
    delete dog;
    delete cat;
    std::cout << std::endl;

    std::cout << "=== TEST 2: Array of Animals ===" << std::endl;
    const int size = 6;
    Animal* animals[size];

    std::cout << "Creating array..." << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\nDeleting array..." << std::endl;
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
    std::cout << std::endl;

    std::cout << "=== TEST 3: Deep Copy with Copy Constructor ===" << std::endl;
    std::cout << "Creating original dog..." << std::endl;
    Dog original;
    std::cout << "\nCreating copy in new scope..." << std::endl;
    {
        Dog copy = original;
        std::cout << "Copy created. Leaving scope..." << std::endl;
    }
    std::cout << "Scope ended. Original should still be valid." << std::endl;
    original.makeSound();
    std::cout << std::endl;

    std::cout << "=== TEST 4: Deep Copy with Assignment Operator ===" << std::endl;
    std::cout << "Creating two dogs..." << std::endl;
    Dog dog1;
    Dog dog2;
    std::cout << "\nAssigning dog1 = dog2..." << std::endl;
    dog1 = dog2;
    std::cout << "Assignment complete. Both should be independent." << std::endl;
    std::cout << std::endl;

    std::cout << "=== TEST 5: Copy Constructor with Cat ===" << std::endl;
    Cat originalCat;
    {
        Cat copyCat = originalCat;
        std::cout << "Cat copy created and will be destroyed..." << std::endl;
    }
    std::cout << "Original cat still valid:" << std::endl;
    originalCat.makeSound();
    std::cout << std::endl;

    std::cout << "=== All tests completed ===" << std::endl;
    std::cout << "Run with: valgrind --leak-check=full ./program" << std::endl;
    std::cout << "Expected result: All heap blocks freed, no leaks possible" << std::endl;

    return 0;
}