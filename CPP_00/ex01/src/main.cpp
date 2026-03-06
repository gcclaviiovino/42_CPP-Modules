#include "PhoneBook.hpp"

int main()
{
	PhoneBook new_phonebook;
	std::string	command;

	std::cout << "Hello there, welcome to your new phonebook!" << std::endl;
	new_phonebook.prompt();
	std::cin >> command;

	while (command != "EXIT")
	{
		if (command == "ADD")
		{
			std::cout << "Great, let's add a new contact!" << std::endl;
			if (!new_phonebook.check_contacts())
				std::cout << "Contact limit (8) has been reached, the new contact will substitute the first one." << std::endl;
			new_phonebook.add_contact();
		}
		else if (command == "SEARCH")
		{
			std::cout << "Great, let's first see all your contacts so far!" << std::endl;
			new_phonebook.search_contact();
		}
		else
			std::cout << "Command is not in the list." << std::endl;
		new_phonebook.prompt();
		std::cin >> command;
	}

	if (command == "EXIT")
		return (new_phonebook.exit_phonebook());
}