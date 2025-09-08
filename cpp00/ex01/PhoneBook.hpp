#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
#include <cctype>
#include "Contacts.hpp"


class PhoneBook{
	private:
		Contacts contact[8];
		int		index;
		int		flag;
		
	public:
		PhoneBook();
		void	ADD();
		void	SEARCH();
		bool	is_empty();
};


#endif