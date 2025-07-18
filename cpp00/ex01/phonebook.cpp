#include "phonebook.hpp"

void	add(Phonebook& pb){
	if (pb.index == 8)
		pb.index = 7;
	std::cout<<"first name: ";
	std::getline(std::cin, pb.contact[pb.index].first_name);
	std::cout<<"last name: ";
	std::getline(std::cin, pb.contact[pb.index].last_name);
	std::cout<<"nackname: ";
	std::getline(std::cin, pb.contact[pb.index].nickname);
	std::cout<<"phone number: ";
	std::getline(std::cin, pb.contact[pb.index].phone);
	std::cout<<"darkest secret: ";
	std::getline(std::cin, pb.contact[pb.index].secret);
	pb.index++;
}
void	search(Phonebook& pb){
	std::string out;
	std::getline(std::cin, out);
	int i=0;
	for(; i < 8; i++){
		if (out.compare(pb.contact[i].first_name) == 0)
			break;
	}
	if (i > 7)
		std::cout<<"name doesn't found\n";
	std::cout<<"First Name: "<<pb.contact[i].first_name<<"\n";
	std::cout<<"Last Name: "<<pb.contact[i].last_name<<"\n";
	std::cout<<"Nickname: "<<pb.contact[i].nickname<<"\n";
	std::cout<<"Phone: "<<pb.contact[i].phone<<"\n";
	std::cout<<"Secret: "<<pb.contact[i].secret<<"\n";
}

void	clean_exit(){
	exit(0);
}

void	check(Phonebook& pb, std::string test){
	if (test.compare("ADD") == 0)
		add(pb);
	else if (test.compare("SEARCH") == 0)
		search(pb);
	else if (test.compare("EXIT") == 0)
		clean_exit();
	else
		std::cout<<"Error:\n";
}

void	display(){
	std::cout<<"Enter a command sir:\n";
	std::cout<<"ADD    :\nSEARCH :\nEXIT   :\n";
	std::cout<<"> ";
}

int main(int ac, char **av)
{
	Phonebook pb;
	pb.index = 0;
	if (ac != 1){
		std::cout<<"Error\n";return 1;}
	display();
	std::string out;
	while (std::getline(std::cin, out)){
		system("clear");
		check(pb, out);
		display();
	}
	return 0;
}