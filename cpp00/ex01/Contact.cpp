#include "PhoneBook.hpp"
#include "Contact.hpp"

/*SETTERS*/
void    Contacts::setFirstName( std::string n){
    first_name = n;
}
void	Contacts::setLastName(std::string n){
    last_name = n;
}
void    Contacts::setNickname(std::string n){
    nickname = n;
}
void    Contacts::setPhone(std::string n){
    phone = n;
}
void    Contacts::setSecret(std::string n){
    secret = n;
}
/*GETTERS*/
std::string    Contacts::getFirstName(){
    return first_name;
}
std::string    Contacts::getLastName(){
    return last_name;
}
std::string    Contacts::getNickname(){
    return nickname;
}
std::string    Contacts::getPhone(){
    return phone;
}
std::string    Contacts::getSecret(){
    return secret;
}