#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

int	RobotomyRequestForm::randomise() const
{
	if (time(NULL) % 2 == 0)
		return (0);
	else
		return (1);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	if (RobotomyRequestForm::randomise() == 0)
		std::cout << target << " has been successfully robotomised." << std::endl;
	else
		std::cout << "Robotomy of " << target << " failed." << std::endl;
}