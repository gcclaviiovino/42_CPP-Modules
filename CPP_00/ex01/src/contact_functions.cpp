#include "PhoneBook.hpp"

bool	Contact::firstname_put(std::string& firstname)
{
	if (firstname.empty())
		return (false);
	this->firstName = firstname;
	return (true);
}

bool	Contact::lastname_put(std::string& lastname)
{
	if (lastname.empty())
		return (false);
	this->lastName = lastname;
	return (true);
}

bool	Contact::nickname_put(std::string& nickname)
{
	if (nickname.empty())
		return (false);
	this->nickname = nickname;
	return (true);
}

bool	Contact::number_put(std::string& number)
{
	if (number.empty())
		return (false);
	int len = number.length();

	if (len < 10 || len > 15)
	{
		std::cout << "Wrong number format, please try again." << std::endl;
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

bool	Contact::secret_put(std::string& secret)
{
	if (secret.empty())
		return (false);
	this->darkest_secret = secret;
	return (true);
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