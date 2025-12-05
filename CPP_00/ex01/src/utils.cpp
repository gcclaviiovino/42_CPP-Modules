#include "PhoneBook.hpp"

void	PhoneBook::not_found()
{
	std::cout << "Error 404: contact not found" << std::endl;
	std::cout << "To add a new contact, when prompted to select a command, write ADD" << std::endl;
}

void	PhoneBook::not_in_range()
{
	std::cout << "Error 400: bad request." << std::endl;
	std::cout << "Contact id must be in range [0-7]" << std::endl;
}

std::string PhoneBook::format_column(const std::string& text)
{
	const int	COL_WIDTH = 10;

	if (text.length() > COL_WIDTH)
		return (text.substr(0, COL_WIDTH - 1) + ".");

	int	padding = COL_WIDTH - text.length();
	return (text + std::string(padding, ' '));
}

void	PhoneBook::display_all()
{
	if (this->tot == 0)
		return ;
	int	n_contacts = (this->tot < 8) ? this->tot : 8;
	for (int i = 0; i < n_contacts; i ++)
		this->show_contact(this->contacts[i], i);
}

int	PhoneBook::exit_phonebook()
{
	std::string	sure;
	std::cout << "Your contacts are going to be lost forever. Are you sure you want to exit? (y/n)" << std::endl;
	std::cin >> sure;

	if (sure == "y" || sure == "Y")
		std::cout << "K, bye." << std::endl;
	else if (sure == "n" || sure == "N")
		std::cout << "Too bad." << std::endl;
	else
		std::cout << "Whatever." << std::endl;
	return (0);
}

void	PhoneBook::prompt()
{
	std::cout << "Please select one of the following commands:" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "EXIT" << std::endl;
}

bool	PhoneBook::check_contacts()
{
	if (this->last_id == 7)
		return (false);
	return (true);
}