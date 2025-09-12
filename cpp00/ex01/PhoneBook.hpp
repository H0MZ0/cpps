#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <cctype>
# include "Contact.hpp"


class PhoneBook{
	private:
		Contact contact[8];
		int		index;
		int		flag;

	public:
		PhoneBook();
		void	ADD();
		void	SEARCH();
		bool	is_empty();
};


#endif