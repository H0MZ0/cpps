#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
    x++;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string str[] = {"hello", "world"};
    const int constArr[] = {10, 20, 30};

    std::cout << "Print int array:" << std::endl;
    iter(arr, 5, print<int>);

    std::cout << "Increment int array:" << std::endl;
    iter(arr, 5, increment<int>);
    iter(arr, 5, print<int>);

    std::cout << "Print string array:" << std::endl;
    iter(str, 2, print<std::string>);

    std::cout << "Print const int array:" << std::endl;
    iter(constArr, 3, print<int>);

    return 0;
}
