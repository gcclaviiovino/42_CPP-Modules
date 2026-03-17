#include "PhoneBook.hpp"

void	PhoneBook::add_contact() {
	Contact	new_contact;
	std::string	firstname;

	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, firstname);
	if (!new_contact.firstname_put(firstname))
		return (PhoneBook::empty_input());

	std::string	lastname;

	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, lastname);
	if (!new_contact.lastname_put(lastname))
		return (PhoneBook::empty_input());

	std::string	nickname;

	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, nickname);
	if (!new_contact.nickname_put(nickname))
		return (PhoneBook::empty_input());

	std::string number;

	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, number);
	if (!new_contact.number_put(number))
		return ;

	std::string	secret;

	std::cout << "Enter darkest secret:" << std::endl;
	std::getline(std::cin, secret);
	if (!new_contact.secret_put(secret))
		return (PhoneBook::empty_input());

	int	index = this->tot % 8;
	this->contacts[index] = new_contact;
	this->tot++;
	this->last_id = index;

	std::cout << "Contact ";
	std::cout << nickname;
	std::cout << " added successfully!" << std::endl;
}

bool	PhoneBook::search_contact() {
	this->display_all();

	std::string	id_str;
	std::cout << "Now enter the id of the contact you want to display:" << std::endl;
	std::getline(std::cin, id_str);
	if (id_str.empty() || id_str.find_first_not_of("0123456789") != std::string::npos)
		return (PhoneBook::not_in_range(), false);

	int id;
	std::istringstream(id_str) >> id;
	if (std::istringstream(id_str).fail())
		return (PhoneBook::not_in_range(), false);
	if (id >= 8 || id < 0)
		return (PhoneBook::not_in_range(), false);
	if (id > this->tot - 1)
		return (PhoneBook::not_found(), false);
	this->show_single_contact(contacts[id], id);
	return (true);
}

int	PhoneBook::exit_phonebook()
{
	std::string	sure;
	std::cout << "Your contacts are going to be lost forever. Are you sure you want to exit? (y/n)" << std::endl;
	
	std::getline(std::cin, sure);
	if (sure == "y" || sure == "Y")
		std::cout << "K, bye." << std::endl;
	else if (sure == "n" || sure == "N")
		std::cout << "Too bad." << std::endl;
	else
		std::cout << "Whatever." << std::endl;
	return (0);
}
