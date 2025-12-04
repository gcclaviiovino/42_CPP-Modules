#include <iostream>
#include <ctype.h>

void	error(void)
{
	std::cout << "* LOUD AND UMBEARABLE FEEDBACK NOISE *" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 1 || !av[1])
		return (error(), 1);

	int	j = 1;
	bool	printed_space = false;

	while (j < ac)
	{
		char		*s = av[j];
		int			i = 0;

		while (s[i])
		{
			char	c = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
			if (std::isspace(static_cast<unsigned char>(c)))
			{
				if (!printed_space)
				{
					std::cout << ' ';
					printed_space = true;
				}

			}
			else
			{
				std::cout << c;
				printed_space = false;
			}
			i ++;
		}
		if (j < ac - 1)
		{
			if (!printed_space)
			{
				std::cout << ' ';
				printed_space = true;
			}
		}
		j ++;
	}
	std::cout << std::endl;
}
