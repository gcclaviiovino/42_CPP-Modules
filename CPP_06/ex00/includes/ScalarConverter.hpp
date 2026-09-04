#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
# include <limits>
# include <math.h>
# include <iomanip>

class	ScalarConverter {
	private:
	ScalarConverter();

	public:
	static void	convert(const std::string &lit);
	ScalarConverter( const ScalarConverter &other );
	ScalarConverter&	operator=( const ScalarConverter &other );
	~ScalarConverter();
};

enum e_type {
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	PSEUDO,
	PSEUDOF,
	ERROR
};

#endif