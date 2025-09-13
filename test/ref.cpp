#include <iostream>

int main(){
	int a = 10;

	int& b = a;
	std::cout << "a=" << a << std::endl << "b=" << b << std::endl;
	a = 20;
	std::cout << "a=" << a << std::endl << "b=" << b << std::endl;

}