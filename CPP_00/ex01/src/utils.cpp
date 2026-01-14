#include "PhoneBook.hpp"

void	PhoneBook::not_found()
{
	std::cout << "Error 404: contact not found." << std::endl;
	std::cout << "To add a new contact, when prompted to select a command, write ADD." << std::endl;
}

void	PhoneBook::not_in_range()
{
	std::cout << "Error 400: bad request." << std::endl;
	std::cout << "Contact id must be in range [0-7]." << std::endl;
}

std::string PhoneBook::format_column(const std::string& text)
{
	const int	COL_WIDTH = 10;

	if (text.length() > COL_WIDTH)
		return (text.substr(0, COL_WIDTH - 1) + ".");

	int	padding = COL_WIDTH - text.length();
	return (std::string(padding, ' ') + text);
}

void	PhoneBook::display_all()
{
	if (this->tot == 0)
		return ;
	int	n_contacts = (this->tot < 8) ? this->tot : 8;
	std::cout << "=============================================" << std::endl;
	for (int i = 0; i < n_contacts; i ++)
		this->display_contact(this->contacts[i], i);
	std::cout << "=============================================" << std::endl;
}

void	PhoneBook::display_contact(Contact& contact, int id)
{
	std::ostringstream oss;
	oss << id;

	std::string	id_string = oss.str();
	std::cout << "|";
	std::cout << format_column(id_string) << "|";
	std::cout << format_column(contact.firstname_get()) << "|";
	std::cout << format_column(contact.lastname_get()) << "|";
	std::cout << format_column(contact.nickname_get()) << "|";
	std::cout << std::endl;
	if (id < last_id)
		std::cout << "--------------------------------------------" << std::endl;
}

void	PhoneBook::show_single_contact(Contact& contact, int id)
{
	std::string	firstname = contact.firstname_get();
	std::string	lastname = contact.lastname_get();
	std::string	nickname = contact.nickname_get();
	std::string	phone = contact.number_get();
	std::string	secret = contact.secret_get();

	std::stringstream ss;
	ss << id;
	std::string id_str = ss.str();

	int len = std::max(firstname.length(), 
				std::max(lastname.length(), 
				std::max(nickname.length(), 
				std::max(phone.length(), secret.length()))));

	std::cout << std::endl;
	std::cout << justify_center("id: " + id_str, len) << std::endl;
	std::cout << justify_center("firstname: " + firstname, len) << std::endl;
	std::cout << justify_center("lastname: " + lastname, len) << std::endl;
	std::cout << justify_center("nickname: " + nickname, len) << std::endl;
	std::cout << justify_center("phone number: " + phone, len) << std::endl;
	std::cout << justify_center("secret: " + secret, len) << std::endl;
	std::cout << std::endl;
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

std::string	PhoneBook::justify_center(std::string content, int len)
{
	return(std::string(len, ' ') + content);
}