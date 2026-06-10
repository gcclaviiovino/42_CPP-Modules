#include "Bureaucrat.hpp"

int main() 
{
	// VALID GRADE
	try
	{
		Bureaucrat highRankBureaucrat("Pippo Serio", 2);
		std::cout << highRankBureaucrat << std::endl;

		Bureaucrat mediumRankBureaucrat("Pippo Medio", 70);
		std::cout << mediumRankBureaucrat << std::endl;

		Bureaucrat lowRankBureaucrat("Pippo Chill", 149);
		std::cout << lowRankBureaucrat << std::endl;

		Form		easyForm("Richiesta CIE", 150, 150);
		std::cout << easyForm << std::endl;

		Form		mediumForm("Pagamento TARI", 70, 70);
		std::cout << mediumForm << std::endl;

		Form		hardForm("Voltura fornitore elettricità", 2, 2);
		std::cout << hardForm << std::endl;


		// CORRECT SIGNING
		highRankBureaucrat.signForm(mediumForm);
		lowRankBureaucrat.signForm(easyForm);

		// INCORRECT SIGNING
		mediumRankBureaucrat.signForm(hardForm);

		// FINAL FORM STATUS PRINT
		std::cout << easyForm << std::endl;
		std::cout << mediumForm << std::endl;
		std::cout << hardForm << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// INVALID GRADES
	try
	{
		Form invalidForm("Form Invalido", 151, 15); 
	}
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form zeroGrade("Form Zero", 30, 0); 
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form negativeGrade("Form Negativo", -10, 10); 
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}