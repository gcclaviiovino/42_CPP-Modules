#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string level;
	Harl	Harl;
	std::stringstream ss;

	(void)ac;
	if (!av[1])
		return (1);
	ss << av[1];
	ss >> level;
	Harl.complain(level);
}