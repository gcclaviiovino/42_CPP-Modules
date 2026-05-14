#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& newName)
	: ClapTrap(newName + "_clap_name"), ScavTrap(newName), FragTrap(newName), name(newName)
{
	// std::cout << "Diamond default constructor called" << std::endl;
	ClapTrap::hitPoints = FragTrap::hitPoints;
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	ClapTrap::attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	// std::cout << "Diamond copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	// std::cout << "Diamond assignment operator called" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	// std::cout << "Diamond destructor constructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << name << " is my Diamond name!" << std::endl;
	std::cout << ClapTrap::name << " is my Claptrap name!" << std::endl;
}