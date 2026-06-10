#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name(""), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& newName, int newGrade)
	: name(newName)
{
	isGradeValid(newGrade);
	grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name), grade(other.grade)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high. Valid range is [1-150].");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low. Valid range is [1-150].");
}

void	Bureaucrat::isGradeValid(int currGrade)
{
	if (currGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (currGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	isGradeValid(grade - 1);
	this->grade --;
}

void	Bureaucrat::decrementGrade()
{
	isGradeValid(grade + 1);
	this->grade ++;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}

void	Bureaucrat::signForm(Form& f)
{
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getFormName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << f.getFormName();
		std::cout << " because " << e.what() << std::endl;
	}
}