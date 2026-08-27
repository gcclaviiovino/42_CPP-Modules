#include "AForm.hpp"

AForm::AForm()
	: formName(""), isSigned(false), gradeToSign(1), gradeToExec(1)
{}

AForm::AForm(const std::string& name, const int toSign, const int toExec)
	: formName(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
	isGradeValid(toSign);
	isGradeValid(toExec);
}

AForm::AForm(const AForm& other)
	: formName(other.formName), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
		gradeToExec(other.gradeToExec)
{}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm()
{}

void	AForm::isGradeValid(int currGrade)
{
	if (currGrade < 1)
		throw AForm::GradeTooHighException();
	else if (currGrade > 150)
		throw AForm::GradeTooLowException();
}

void	AForm::isGradeValid(int currGrade, int target)
{
	if (currGrade > target)
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high. The required operation cannot be performed.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low. The required operation cannot be performed.");
}

const std::string&	AForm::getFormName() const
{
	return (formName);
}

bool	AForm::getFormStatus() const
{
	return (isSigned);
}

int	AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (gradeToExec);
}

void	AForm::beSigned(Bureaucrat& b)
{
	isGradeValid(b.getGrade(), gradeToSign);
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& out, const AForm& f)
{
	out << f.getFormName() << " with status: ";
	if (f.getFormStatus())
		std::cout << "signed.";
	else
		std::cout << "not signed.";
	out << "\nGrade required to sign: " << f.getGradeToSign();
	out << "; grade required to execute: " << f.getGradeToExec() << ".";
	return (out);
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("The requested form is not signed. The required operation cannot be performed.");
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!isSigned)
		throw AForm::FormNotSignedException();
	const_cast<AForm*>(this)->isGradeValid(executor.getGrade(), gradeToExec);
}