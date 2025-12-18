#include "Zombie.hpp"

int	main(void)
{
	std::string	name;

	// Zombie with allocation
	std::cout << "Enter the name of your heap Zombie:" << std::endl;
	std::cin >> name;

	Zombie	*heap_zombie = newZombie(name);
	heap_zombie->announce();

	delete heap_zombie;

	// Zombie without allocation
	std::cout << "Enter the name of your stack Zombie:" << std::endl;
	std::cin >> name;

	randomChump(name);
}