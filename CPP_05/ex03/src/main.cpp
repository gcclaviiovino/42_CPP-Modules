#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	try
	{
		Bureaucrat bureaucrat("Pippo Serio", 2);
		std::cout << bureaucrat << std::endl;

		// CORRECT FORM ITER
		AForm	*form1 = intern.makeForm("robotomy request", "Beep");
		if (form1) {
			bureaucrat.signForm(*form1);
			bureaucrat.executeForm(*form1);
		}

		// WRONG FORM NAME
		AForm	*form2 = intern.makeForm("very nice form", "Wow");
		if (form2) {
			bureaucrat.signForm(*form2);
			bureaucrat.executeForm(*form2);
		}

		if (form1)
			delete form1;
		if (form2)
			delete form2;
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}