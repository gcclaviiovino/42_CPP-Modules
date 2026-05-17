#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	mind = new Brain;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	mind = new Brain(*other.mind);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*mind = *other.mind;
	}
	return(*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete(mind);
}

void	Dog::makeSound() const
{
	std::cout << "WHOF WHOOOF" << std::endl;
}