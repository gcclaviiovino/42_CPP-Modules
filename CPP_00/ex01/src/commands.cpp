#include "PhoneBook.hpp"

void	PhoneBook::add_contact() {
	Contact	new_contact;
	std::string	firstname;

	std::cout << "Enter first name:" << std::endl;
	std::cin >> firstname;
	new_contact.firstname_put(firstname);

	std::string	lastname;

	std::cout << "Enter last name:" << std::endl;
	std::cin >> lastname;
	new_contact.lastname_put(lastname);

	std::string	nickname;

	std::cout << "Enter nickname:" << std::endl;
	std::cin >> nickname;
	new_contact.nickname_put(nickname);

	std::string number;

	std::cout << "Enter phone number:" << std::endl;
	std::cin >> number;
	if (!new_contact.number_put(number))
		return ;

	std::string	secret;

	std::cout << "Enter darkest secret:" << std::endl;
	std::cin >> secret;
	new_contact.secret_put(secret);

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

	int	id;
	std::cout << "Now enter the id of the contact you want to display:" << std::endl;
	std::cin >> id;
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
	std::cin >> sure;

	if (sure == "y" || sure == "Y")
		std::cout << "K, bye." << std::endl;
	else if (sure == "n" || sure == "N")
		std::cout << "Too bad." << std::endl;
	else
		std::cout << "Whatever." << std::endl;
	return (0);
}
