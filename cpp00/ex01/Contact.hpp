#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <sstream>

class Contact{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	public :
		/*GETTERS*/
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhone();
		std::string	getSecret();
		/*SETTERS*/
		void		setFirstName( std::string n);
		void		setLastName(std::string n);
		void		setNickname(std::string n);
		void		setPhone(std::string n);
		void		setSecret(std::string n);
};

#endif