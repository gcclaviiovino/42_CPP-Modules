#include "Bureaucrat.hpp"

int main() 
{
	// VALID GRADE
	try
	{
		Bureaucrat bureaucrat("Pippo", 20);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// INVALID GRADES
	try
	{
		Bureaucrat invalidBureaucrat("Pippo Invalido", 151); 
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat zeroGrade("Pippo Zero", 0); 
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat negativeGrade("Pippo Negativo", -10); 
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// INVALID INCREMENT/DECREMENT
	try
	{
		Bureaucrat highEdgeCase("Pippo al limite(alto)", 1);
		std::cout << highEdgeCase << std::endl;

		highEdgeCase.incrementGrade();
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat lowEdgeCase("Pippo al limite(basso)", 150);
		std::cout << lowEdgeCase << std::endl;

		lowEdgeCase.decrementGrade();
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}