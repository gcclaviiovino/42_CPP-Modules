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

bool	Contact::number_put(std::string& number)
{
	int len = number.length();

	if (len < 10 || len > 15)
	{
		std::cout << "Wrong number fromat, please try again." << std::endl;
		return (false);
	}
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(number[i]))
		{
			std::cout << "A 'phone number' must be a sequence of digits." << std::endl;
			return (false);
		}
	}
	this->phone_number = number;
	return (true);
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

std::string Contact::number_get()
{
	return (this->phone_number);
}

std::string Contact::secret_get()
{
	return (this->darkest_secret);
}