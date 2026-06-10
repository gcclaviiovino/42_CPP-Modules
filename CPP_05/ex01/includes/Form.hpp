#ifndef FORM_HPP
# define FORM_HPP

# include <stdbool.h>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
	private:
	const std::string	formName;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExec;
	void				isGradeValid( int grade );
	void				isGradeValid( int grade, int target);

	public:
	Form();
	Form( const std::string& name, const int toSign, const int toExec );
	Form( const Form& other );
	Form&	operator=( const Form& other );
	~Form();

	const std::string&	getFormName() const;
	bool				getFormStatus() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	void				beSigned(Bureaucrat& b);

	class	GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& out, const Form& f );

#endif