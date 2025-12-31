#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const std::string& name, int grade) {

}

Intern::Intern(const Intern& other) {

}

Intern& Intern::operator=(const Intern& other) {

}

void Intern::makeForm(std::string name, std::string form){
    !name.empty() ? std::cout << "Intern creates " << form << std::endl
                  : std::cerr << "Intern has problem" << std::endl;
}

