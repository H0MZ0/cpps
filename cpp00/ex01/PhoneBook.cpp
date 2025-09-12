#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(){
	flag = 0;
	index = 0;
}

bool	PhoneBook::is_empty()
{
	if(contact[index].getFirstName().empty()
	|| contact[index].getLastName().empty()
	|| contact[index].getNickname().empty()
	|| contact[index].getPhone().empty()
	|| contact[index].getSecret().empty()){
		std::cerr<<"Retry again!\n";
		ADD();
		return true;
	}
	return false;
}

void PhoneBook::ADD() {
    if (index == 8) index = 0;
    std::string out;

    std::cout << "first name: ";
    if (!std::getline(std::cin, out)) return;
    contact[index].setFirstName(out);

    std::cout << "last name: ";
    if (!std::getline(std::cin, out)) return;
    contact[index].setLastName(out);

    std::cout << "nickname: ";
    if (!std::getline(std::cin, out)) return;
    contact[index].setNickname(out);

    std::cout << "phone: ";
    if (!std::getline(std::cin, out)) return;
    contact[index].setPhone(out);

    std::cout << "secret: ";
    if (!std::getline(std::cin, out)) return;
    contact[index].setSecret(out);

    if (is_empty()) return;
    index++;
    if (index == 8) flag = 1;
}
void	write_range(std::string out){
	if (out.length() > 10)
		std::cout << out.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << out << "|";
}

void	PhoneBook::SEARCH(){
	if (index == 0){
		std::cout << "No Contact yet" << std::endl; return ;}
	std::cout<<"     Index| FirstName|  LastName|  NickName|\n";
	int	max, in;
	if (flag) max = 8; else max = index;
	for(int i = 0; i < max; i++){
		std::cout << "         " << i + 1 << "|";
		write_range(contact[i].getFirstName());
		write_range(contact[i].getLastName());
		write_range(contact[i].getNickname());
		// write_range(contact[i].getPhone());
		std::cout<< "\n";
	}
	std::string out;
	std::cout << "Index ->";
	getline(std::cin, out);
	if (!out.empty()){
		std::stringstream ss(out);
		ss >> in;
		in--;
		if (in > 8 || in < 0 || ss.fail() || in >= max){
			std::cerr << "Invalid Index\n";
			return ;
		}
		std::cout << "FirstName :" << contact[in].getFirstName() << "\n";
		std::cout << "LastName  :"  << contact[in].getLastName() << "\n";
		std::cout << "NickName  :"  << contact[in].getNickname() << "\n";
		std::cout << "Phone     :"  << contact[in].getPhone() << "\n";
		std::cout << "Secret    :"  << contact[in].getSecret() << "\n";
	}
}

void	check(PhoneBook *pb, std::string cmd){
	if (cmd.empty()){
		return ;
	}
	if (cmd.compare("ADD") == 0)
		pb->ADD();
	else if (cmd.compare("SEARCH") == 0)
		pb->SEARCH();
	else if (cmd.compare("EXIT") == 0)
		exit (0);
	else{
		return;
	}
}

int main(){
	PhoneBook	pb;
	std::cout<<"Type a command: {ADD, SEARCH, EXIT}\n>> ";
	std::string out;
	while(std::getline(std::cin, out)){
		check(&pb, out);
		std::cout<<"Type a command: {ADD, SEARCH, EXIT}\n>> ";
	}
}
