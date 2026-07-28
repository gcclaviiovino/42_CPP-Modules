#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class AForm;

class	RobotomyRequestForm: public AForm {
	private:
	std::string	target;
	int			randomise() const;

	public:
	RobotomyRequestForm( const std::string& target );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
	virtual	~RobotomyRequestForm();
	void	execute( Bureaucrat const & executor ) const;
};

#endif