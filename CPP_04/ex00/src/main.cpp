#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* man = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << man->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	man->makeSound();
	cat->makeSound();
	dog->makeSound();

	const	WrongAnimal*	wrongAnimal = new WrongAnimal();
	const	WrongCat*		wrongCat = new WrongCat();

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete(man);
	delete(dog);
	delete(cat);
	delete(wrongAnimal);
	delete(wrongCat);
}