#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
	const std::string	name;
	int					grade;
	void				isGradeValid( int grade );

	public:
	Bureaucrat();
	Bureaucrat( const std::string& name, int garde );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat&	operator=( const Bureaucrat& other );
	~Bureaucrat();

	const std::string&	getName( void ) const;
	int					getGrade( void ) const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm( AForm& f );

	class	GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
	
	void	executeForm(AForm const & form) const;
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& b );

#endif