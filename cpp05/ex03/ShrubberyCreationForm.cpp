#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation", 72, 45), target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other){
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > 137)
        throw GradeTooLowException();
    std::ofstream outfile((target+"_shrubbery").c_str());
    if (!outfile)
        std::cerr << "Problem to create shrubbery" << std::endl;
    outfile << "         ox\n";
    outfile << "        oo oxoo\n";
    outfile << "      xoo   ooxoo\n";
    outfile << "    oxoxoo   ooxoo\n";
    outfile << "  ooxoxo oo  oxoxooo\n";
    outfile << " oooo xxoxoo ooo ooox\n";
    outfile << " oxo o oxoxo  xoxxoxo\n";
    outfile << "  oxo xooxoooo o ooo\n";
    outfile << "    ooo\\oo\\  /o/o\n";
    outfile << "        \\  \\/ /\n";
    outfile << "         |   /\n";
    outfile << "         |  |\n";
    outfile << "         | D|\n";
    outfile << "         |  |\n";
    outfile << "         |  |\n";
    outfile << "  ______/____\\____\n";
    std::cout << "Shrubbery ->" << target << " has been created successfully" << std::endl;
}

