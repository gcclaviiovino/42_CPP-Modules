#include "Harl.hpp"

int	main()
{
	std::string level;
	Harl	Harl;

	std::cout << "What should Harl complain about?" << std::endl;
	std::cin >> level;

	Harl.complain(level);
}