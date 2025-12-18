#include "Zombie.hpp"

Zombie::Zombie(std::string name):
	name(name) {}

Zombie::~Zombie(void) {
	std::cout << name << " has been destroyed";
	std::cout << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}