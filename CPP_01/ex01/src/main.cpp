#include "Zombie.hpp"

int	main()
{
	std::string name;
	int			N;

	std::cout << "What should the Horde name be?" << std::endl;
	std::cin >> name;

	std::cout << "How many zombies should there be? " << std::endl;
	std::cin >> N;

	Zombie	*horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}