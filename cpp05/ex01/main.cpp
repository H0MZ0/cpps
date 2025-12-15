#include "Bureaucrat.hpp"
#include <exception>
#include <stdexcept>

int main(){
    Bureaucrat hamza("hamza", 140);
    try {
        for (int i = 140; i < 160; i++){
            hamza--;
            std::cout << hamza;
        }
    } 
    catch (std::exception & e){
        hamza.GradeTooLowException();
    }
    return 0;
}
