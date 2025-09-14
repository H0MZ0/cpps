#include <iostream>

namespace test
{
    void hello(std::string str){
        std::cout << str;
    }

    int x = 0;
}

void hello(std::string str)
{
    std::cout << str;
}

namespace test1
{
    void hello(std::string str){
        std::cout << str;
    }
    void print()
    {
        std::cout << test::x;
    }
}

int main(){
    hello("hello");
}