#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>

class Contacts{
	public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
};

class Phonebook{
	public:
	Contacts contact[8];
	int		 index;
	int		 total;
};


#endif