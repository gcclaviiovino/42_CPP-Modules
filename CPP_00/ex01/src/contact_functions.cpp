#include "PhoneBook.hpp"

void	Contact::firstname_put(std::string& firstname)
{
	this->firstName = firstname;
}

void	Contact::lastname_put(std::string& lastname)
{
	this->lastName = lastname;
}

void	Contact::nickname_put(std::string& nickname)
{
	this->nickname = nickname;
}

void	Contact::number_put(std::string& number)
{
	this->phone_number = number;
}

void	Contact::secret_put(std::string& secret)
{
	this->darkest_secret = secret;
}

std::string	Contact::firstname_get()
{
	return (this->firstName);
}

std::string	Contact::lastname_get()
{
	return (this->lastName);
}

std::string	Contact::nickname_get()
{
	return (this->nickname);
}