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
	if (id >= 8)
		return (PhoneBook::not_in_range(), false);
	if (id > this->tot - 1)
		return (PhoneBook::not_found(), false);
	this->show_single_contact(contacts[id], id);
	return (true);
}

void	PhoneBook::display_contact(Contact& contact, int id)
{
	std::ostringstream oss;
	oss << id;

	std::string	id_string = oss.str();
	std::cout << format_column(id_string) << "|";
	std::cout << format_column(contact.firstname_get()) << "|";
	std::cout << format_column(contact.lastname_get()) << "|";
	std::cout << format_column(contact.nickname_get());
	std::cout << std::endl;
}

void	PhoneBook::show_single_contact(Contact& contact, int id)
{
	std::cout << "id: " << id << std::endl;
	std::cout << "firstname: " << contact.firstname_get() << std::endl;
	std::cout << "lastname: " << contact.lastname_get() << std::endl;
	std::cout << "nickname: " << contact.nickname_get() << std::endl;
	std::cout << "phone number: " << contact.number_get() << std::endl;
	std::cout << "secret: " << contact.secret_get() << std::endl;
}