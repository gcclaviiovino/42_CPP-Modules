#ifndef AFORM_HPP
# define AFORM_HPP

# include <stdbool.h>
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class	AForm {
	private:
	const std::string	formName;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExec;
	void				isGradeValid( int grade );
	void				isGradeValid( int grade, int target);
	
	protected:
	AForm();
	AForm( const std::string& name, const int toSign, const int toExec );

	public:
	AForm( const AForm& other );
	AForm&	operator=( const AForm& other );
	virtual	~AForm();

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

	class	FormNotSignedException : public std::exception {
		virtual const char* what() const throw();
	};

	virtual void	execute(Bureaucrat const & executor) const ;
};

std::ostream&	operator<<( std::ostream& out, const AForm& f );

#endif