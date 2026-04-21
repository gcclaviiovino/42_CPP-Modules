#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
	int	val;
	static const int	fractional = 8;

	public:
	Fixed();
	Fixed( const int num );
	Fixed( const float num );
	Fixed( const Fixed &other );
	Fixed& operator=( const Fixed& other );
	~Fixed();
	int		getRawBits( void ) const; // get raw val of fixed-point value
	void	setRawBits( int const raw ); // set raw val of fixed-point value
	float	toFloat( void ) const; // converts fixed-point val in floating point num
	int		toInt( void ) const; // converts fixed-point val in int num
};

std::ostream &operator<<(std::ostream &out, const Fixed &val);

#endif