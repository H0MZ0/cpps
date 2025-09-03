#include "test.hpp"

Test::Test(){
    std::cout << "Default Constructor is called" << std::endl;
    age = 23;
    // name = "hamza";
}

Test::~Test(){
    std::cout<<"Default Destructor is called"<< std::endl;
}

void Test::display(std::string name){
    std::cout << "Name is : " << name << std::endl;
    std::cout << "Age is : " << age << std::endl;
}

int main(){
    Test t1;
    t1.display("hassan");
    std::cout<<std::endl;
    Test t2;
    t2.display("hamza");
    // ~Test();
}