#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:name(name), weapon(NULL)
{}

HumanB::HumanB(std::string name, Weapon *weapon)
	:name(name), weapon(weapon)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType();
	else
		std::cout << this->name << " has no weapon to attack!";
	std::cout << std::endl;
}