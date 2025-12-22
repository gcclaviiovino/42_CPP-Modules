#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <stdbool.h>

class Contact {
	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public:
	void	firstname_put(std::string& first_name);
	void	lastname_put(std::string& last_name);
	void	nickname_put(std::string& nickname);
	bool	number_put(std::string& number);
	void	secret_put(std::string& secret);

	std::string firstname_get();
	std::string lastname_get();
	std::string nickname_get();
	std::string number_get();
	std::string secret_get();
};

#endif