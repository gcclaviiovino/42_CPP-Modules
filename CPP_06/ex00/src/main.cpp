#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1])
	{
		std::cout << "Error: number of arguments should be exactly 2. Please try again." << std::endl;
		return 1;
	}

	std::string	lit = av[1];
	ScalarConverter::convert(lit);
}