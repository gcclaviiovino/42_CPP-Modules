#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

struct	FormOption {
	int	id;
	std::string	aliases[5];
};

class	Intern {
	private:
	int		matchForm( const std::string& name );
	
	public:
	Intern();
	Intern( const Intern& other );
	Intern&	operator=( const Intern& other );
	~Intern();
	
	AForm	*makeForm( const std::string& formName, const std::string& target );
};

#endif