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

	// COMPARISON OPERATORS
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// ARITHMETIC OPERATORS
	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);

	// INCREMENT/DECREMENT OPERATORS
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	// MINS AND MAXS
	static Fixed&			min(Fixed& n1, Fixed& n2);
	static const Fixed&	min(const Fixed& n1, const Fixed& n2);
	static Fixed&			max(Fixed& n1, Fixed& n2);
	static const Fixed&	max(const Fixed& n1, const Fixed& n2);

};

std::ostream &operator<<(std::ostream &out, const Fixed &val);



#endif