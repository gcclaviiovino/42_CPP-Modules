#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const	FormOption Shrubbery = {
	1,
	{
		"shrubbery",
		"shrubbery creation",
		"shrubberycreation",
		"shrubberycreationform",
		"shrubbery creation form",
	}
};

const	FormOption Robotomy = {
	2,
	{
		"robotomy",
		"robotomy request",
		"robotomyrequest",
		"robotomyrequestform",
		"robotomy request form",
	}
};

const	FormOption Presidential = {
	3,
	{
		"presidential",
		"presidential pardon",
		"presidentialpardon",
		"presidentialpardonform",
		"presidential pardon form",
	}
};

static const FormOption forms[] = { Shrubbery, Robotomy, Presidential };
static const std::size_t formsCount = sizeof(forms) / sizeof(forms[0]);
static const std::size_t aliasCount = 5;

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

int Intern::matchForm(const std::string& name)
{
	for (std::size_t i = 0; i < formsCount; i++)
	{
		for (std::size_t j = 0; j < aliasCount; j++)
		{
			if (forms[i].aliases[j] == name)
				return forms[i].id;
		}
	}
	return 0;
}

AForm *Intern::makeForm(const std::string& formName, const std::string& target)
{
	int id = matchForm(formName);

	switch (id)
	{
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 3:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Error: no such form. Intern couldn't proceed." << std::endl;
			return NULL;
	}
}