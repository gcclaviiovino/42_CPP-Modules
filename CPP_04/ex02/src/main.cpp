#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog	*dog = new Dog;
	Cat	*cat = new Cat;
	// Animal	*animal = new Animal;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}