#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	// VALID GRADE
	try
	{
		Bureaucrat highRankBureaucrat("Pippo Serio", 2);
		std::cout << highRankBureaucrat << std::endl;

		Bureaucrat mediumRankBureaucrat("Pippo Medio", 70);
		std::cout << mediumRankBureaucrat << std::endl;

		Bureaucrat lowRankBureaucrat("Pippo Chill", 147);
		std::cout << lowRankBureaucrat << std::endl;

		// ATTEMPT TO CREATE FORM DIRECTLY
		// AForm	abstractForm;

		// CORRECT FORM CREATION
		ShrubberyCreationForm	shruberryForm("tree");
		RobotomyRequestForm		robotomyForm("Beep");
		PresidentialPardonForm	presidentialForm("boring stuff");

		std::cout << shruberryForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << presidentialForm << std::endl;

		// CORRECT SIGNING
		try {
			lowRankBureaucrat.signForm(shruberryForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			highRankBureaucrat.signForm(presidentialForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		// INCORRECT SIGNING
		try {
			mediumRankBureaucrat.signForm(presidentialForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		// CORRECT EXECUTION
		try {
			highRankBureaucrat.executeForm(shruberryForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		// INCORRECT EXECUTION
		try {
			highRankBureaucrat.executeForm(robotomyForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		// CORRECT SIGNING AND EXECUTION
		try {
			highRankBureaucrat.signForm(robotomyForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		try {
			highRankBureaucrat.executeForm(robotomyForm);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}