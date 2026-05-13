#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& newName)
	: name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}

	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0  || this->energyPoints == 0 || this->hitPoints < this->attackDamage)
	{
		std::cout << "Stats too low to attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;

	this->energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap gets attacked: " << amount;
	std::cout << " points lost." << std::endl;

	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << "No more energy left." << std::endl;
		return ;
	}
	std::cout << "ClapTrap gets repaired: " << amount;
	std::cout << " points gained." << std::endl;

	this->hitPoints += amount;
	this->energyPoints -= 1;
}