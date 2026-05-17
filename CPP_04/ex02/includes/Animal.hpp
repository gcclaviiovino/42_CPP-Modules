#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal {
	protected:
	std::string	type;
	Animal();

	public:
	Animal( const Animal& other );
	Animal&	operator=( const Animal& other );
	virtual ~Animal();

	const std::string	getType() const;
	virtual	void		makeSound() = 0;
};

#endif