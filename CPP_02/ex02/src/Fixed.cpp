#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->val = other.val;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->val = num << fractional;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->val = static_cast<int>(roundf(num * (1 << fractional))); 	
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->val = other.val;
	return (*this);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

int		Fixed::toInt(void) const
{
	return (this->val >> this->fractional);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->val) / (1 << fractional));
}

std::ostream &operator<<(std::ostream &out, const Fixed &val)
{
	out << val.toFloat();
	return (out);
}

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	res;

	res.setRawBits(this->val + other.val);
	return (res);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	res;

	res.setRawBits(this->val - other.val);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	long long	tmp = static_cast<long long>(this->val) * other.val;
	Fixed	res;

	res.setRawBits(static_cast<int>(tmp >> fractional));
	return (res);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	long long	tmp = static_cast<long long>(this->val) << fractional;
	Fixed		res;

	res.setRawBits(tmp * other.val);
	return (res);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->val > other.val);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->val < other.val);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->val >= other.val);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->val <= other.val);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->val == other.val);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->val != other.val);
}

Fixed	Fixed::operator++()
{
	this->val += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = (*this);
	this->val += 1;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->val -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = (*this);
	this->val -= 1;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& n1, Fixed& n2)
{
	Fixed&	ref = (n1 < n2) ? n1 : n2;

	return (ref);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2)
{
	const Fixed&	ref = (n1 < n2) ? n1 : n2;

	return (ref);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)
{
	Fixed&	ref = (n1 > n2) ? n1 : n2;

	return (ref);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2)
{
	const Fixed&	ref = (n1 > n2) ? n1 : n2;

	return (ref);
}