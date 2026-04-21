#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
	int	val;
	static const int	fractional = 8;

	public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int	getRawBits( void ) const; // get raw val of fixed-point value
	void	setRawBits( int const raw ); // set raw val of fixed-point value
};

#endif