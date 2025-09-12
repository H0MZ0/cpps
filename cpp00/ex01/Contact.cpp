#include "PhoneBook.hpp"
#include "Contact.hpp"

/*SETTERS*/
void    Contact::setFirstName( std::string n){
    first_name = n;
}
void	Contact::setLastName(std::string n){
    last_name = n;
}
void    Contact::setNickname(std::string n){
    nickname = n;
}
void    Contact::setPhone(std::string n){
    phone = n;
}
void    Contact::setSecret(std::string n){
    secret = n;
}
/*GETTERS*/
std::string    Contact::getFirstName(){
    return first_name;
}
std::string    Contact::getLastName(){
    return last_name;
}
std::string    Contact::getNickname(){
    return nickname;
}
std::string    Contact::getPhone(){
    return phone;
}
std::string    Contact::getSecret(){
    return secret;
}