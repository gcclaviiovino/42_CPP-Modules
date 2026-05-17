#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog;
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat;

	animals[2]->makeSound();
	animals[7]->makeSound();

	for (int i = 0; i < 10; i++)
		delete(animals[i]);

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;

	Dog originalDog;
	Dog copiedDog = originalDog;
	copiedDog.makeSound();

	Cat originalCat;
	Cat copiedCat = originalCat;
	copiedCat.makeSound();
}