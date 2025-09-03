#include <iostream>
int main(){
    std::string holded = "HI THIS IS BRAIN";
    std::string* stringPTR = &holded;
    std::string& stringREF = holded;
    std::cout << holded << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    std::cout << &holded << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
}