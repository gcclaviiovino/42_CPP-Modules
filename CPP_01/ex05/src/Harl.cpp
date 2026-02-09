#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout << DEBUG_MSG << std::endl;
}

void	Harl::info()
{
	std::cout << INFO_MSG << std::endl;
}

void	Harl::warning()
{
	std::cout << WARNING_MSG << std::endl;
}

void	Harl::error()
{
	std::cout << ERROR_MSG << std::endl;
}

void	Harl::complain(std::string level)
{
	t_make_complains	complains[] = 
	{{"DEBUG", &Harl::debug}, {"INFO", &Harl::info}, {"WARNING", &Harl::warning}, {"ERROR", &Harl::error}};

	for (int i = 0; i < 4; i++)
	{
		if (complains[i].level == level)
		{
			(this->*complains[i].funct)();
			return ;
		}
	}
}