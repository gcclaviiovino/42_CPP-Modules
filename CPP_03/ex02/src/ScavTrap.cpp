#include "ScavTrap.hpp"

// ScavTrap inherits from ClapTrap, so the base portion of the object must be initialized before the derived part

ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName)
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0  || this->energyPoints == 0 || this->hitPoints < this->attackDamage)
	{
		std::cout << "Stats too low to attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;

	this->energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap now in Gate mode." << std::endl;
}