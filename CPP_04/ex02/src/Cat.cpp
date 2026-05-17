#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	mind = new Brain;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	mind = new Brain(*other.mind);
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*mind = *other.mind;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete(mind);
}

void	Cat::makeSound()
{
	std::cout << "meEeEeeEEEOooOwWWw" << std::endl;
}