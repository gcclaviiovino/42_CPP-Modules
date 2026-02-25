#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG_MSG << std::endl;
	std::cout << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO_MSG << std::endl;
	std::cout << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING_MSG << std::endl;
	std::cout << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR_MSG << std::endl;
	std::cout << std::endl;
}

void	Harl::nonsense()
{
	std::cout << NONSENSE_MSG << std::endl;
}

void	Harl::switch_complain(int lev)
{
	switch (lev)
	{
		case 0 :
			this->debug();
			__attribute__((fallthrough));
		case 1 :
			this->info();
			__attribute__((fallthrough));
		case 2 :
			this->warning();
			__attribute__((fallthrough));
		case 3 :
			this->error();
			__attribute__((fallthrough));
		default :
			break ;
	}
}

void	Harl::complain(std::string level)
{
	t_make_complains	complains[] = 
	{{"DEBUG", &Harl::debug}, {"INFO", &Harl::info}, {"WARNING", &Harl::warning}, {"ERROR", &Harl::error}};

	for (int i = 0; i < 4; i++)
	{
		if (complains[i].level == level)
		{
			this->switch_complain(i);
			return ;
		}
	}
	this->nonsense();
}