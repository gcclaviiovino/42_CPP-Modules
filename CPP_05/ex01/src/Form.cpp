#include "Form.hpp"

Form::Form()
	: formName(""), isSigned(false), gradeToSign(1), gradeToExec(1)
{}

Form::Form(const std::string& name, const int toSign, const int toExec)
	: formName(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
	isGradeValid(toSign);
	isGradeValid(toExec);
}

Form::Form(const Form& other)
	: formName(other.formName), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
		gradeToExec(other.gradeToExec)
{}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

Form::~Form()
{}

void	Form::isGradeValid(int currGrade)
{
	if (currGrade < 1)
		throw Form::GradeTooHighException();
	else if (currGrade > 150)
		throw Form::GradeTooLowException();
}

void	Form::isGradeValid(int currGrade, int target)
{
	if (currGrade > target)
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high. The required operation cannot be performed.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low. The required operation cannot be performed.");
}

const std::string&	Form::getFormName() const
{
	return (formName);
}

bool	Form::getFormStatus() const
{
	return (isSigned);
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (gradeToExec);
}

void	Form::beSigned(Bureaucrat& b)
{
	isGradeValid(b.getGrade(), gradeToSign);
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& out, const Form& f)
{
	out << f.getFormName() << " with status: " << f.getFormStatus();
	out << "\nGrade required to sign: " << f.getGradeToSign();
	out << "; grade required to execute: " << f.getGradeToExec() << ".";
	return (out);
}