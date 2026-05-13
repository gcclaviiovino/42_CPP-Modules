#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& newName) : ClapTrap(newName)
{
	// std::cout << "FragTrap default constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	// std::cout << "FragTrap copy constructor called." << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	// std::cout << "FragTrap assignment called." << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	// std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0  || this->energyPoints == 0 || this->hitPoints < this->attackDamage)
	{
		std::cout << "Stats too low to attack." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;

	this->energyPoints -= 1;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap has requested a high five!." << std::endl;
}