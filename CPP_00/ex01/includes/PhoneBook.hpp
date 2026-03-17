#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <stdbool.h>
# include <sstream>
# include <cstdio>

class PhoneBook {

	private:
	Contact contacts[8];
	int	last_id;
	int	tot;
	std::string	format_column(const std::string& text);
	std::string	justify_center(std::string content, int len);

	public:
	PhoneBook();
	void	add_contact();
	bool	search_contact();
	void	display_contact(Contact& contact, int id);
	void	show_single_contact(Contact& contact, int id);
	int		exit_phonebook();
	void	not_found();
	void	not_in_range();
	void	display_all();
	void	prompt();
	bool	check_contacts();
	void	empty_input();
};

#endif