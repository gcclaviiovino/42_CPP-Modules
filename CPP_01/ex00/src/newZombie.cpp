#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie	*stack_zombie;

	stack_zombie = new Zombie(name);
	return (stack_zombie);
}