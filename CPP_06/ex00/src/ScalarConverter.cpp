#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

static bool	allDigit(const std::string &str)
{
	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

static bool	isPseudo(const std::string &str)
{
	std::string	check = str;
	if (check[0] == '+' || check[0] == '-')
		check = check.substr(1);

	return (check == "inf" || check == "inff" || check == "nan" || check == "nanf");
}

static e_type	parse_input(const std::string &input) {
	if (input.length() == 1)
	{
		if (std::isdigit(input[0]))
			return INT;
		return CHAR;
	}
	else if ((input[0] == '-' || std::isdigit(input[0])) && allDigit(input.substr(1)))
		return INT;
	else if (input.find('.') != std::string::npos)
	{
		if (input.find('f') != std::string::npos)
			return FLOAT;
		return DOUBLE;
	}
	else if (isPseudo(input.c_str()))
	{
		if (input.find("anf") != std::string::npos || input.find("nff") != std::string::npos)
			return PSEUDOF;
		return PSEUDO;
	}

	return ERROR;
}

static void	pseudo_case(const std::string &lit, enum e_type type) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (type == PSEUDO)
		std::cout << "float: " << lit << "f" << std::endl;
	else
		std::cout << "float: " << lit << std::endl;
	if (lit[lit.length() - 1] == 'f' && type == PSEUDOF)
		std::cout << "double: " << lit.substr(0, lit.length() - 1) << std::endl;
	else
		std::cout << "double: " << lit << std::endl;
}

static void	error_case()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	display_all(char c, int i, float f, double d)
{
	std::cout << "char: ";
	if (!std::isprint(c))
	{
		if ((c > 0 && c < 9) || (c >= 11 && c <= 31))
			std::cout << "Not displayable" << std::endl;
		else
			std::cout << "impossible (e.i. NULL or out-of-range input)" << std::endl;
	}
	else
		std::cout << c << std::endl;

	std::cout << "int: ";
	if (i < -std::numeric_limits<int>::max() || i > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	std::cout << "float: ";
	long int	pre = static_cast<long int>(f);
	int suff = (long)(f * 10) % 10;
	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << pre << "." << suff << "f" << std::endl;

	std::cout << "double: ";
	if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::convert(const std::string &lit) {
	e_type	flag = parse_input(lit);
	char	actualChar = -1;
	int		actualInt = -1;
	float	actualFloat = -1.0f;
	double	actualDouble = -1.0;

	long	longValue;

	switch (flag) {
		case CHAR:
		{
			actualChar = lit[0];
			longValue = static_cast<long>(actualChar);
			break;
		}
		case INT:
		{
			actualInt = std::atoi(lit.c_str());
			longValue = std::strtol(lit.c_str(), NULL, 10);
			break;
		}
		case FLOAT:
		case PSEUDOF:
		{
			actualFloat = std::strtof(lit.c_str(), NULL);
			if (flag == PSEUDOF)
			{
				pseudo_case(lit, flag);
				return ;
			}
			longValue = std::strtol(lit.c_str(), NULL, 10);
			break;
		}
		case DOUBLE:
		case PSEUDO:
		{
			actualDouble = std::strtod(lit.c_str(), NULL);
			if (flag == PSEUDO)
			{
				pseudo_case(lit, flag);
				return ;
			}
			longValue = std::strtol(lit.c_str(), NULL, 10);
			break;
		}
		case ERROR:
		{
			error_case();
			return ;
		}
	}

	char	displayChar = (actualChar != -1) ? actualChar : static_cast<char>(
		(actualInt != -1) ? actualInt : ((actualFloat != -1.0f) ? actualFloat :
		((actualDouble != -1.0) ? actualDouble : 0)));
	int		displayInt = (actualInt != -1) ? actualInt : static_cast<int>((displayChar > 0) ? displayChar : longValue);
	float	displayFloat = (actualFloat != -1.0f) ? actualFloat : static_cast<float>(longValue);
	double	displayDouble = (actualDouble != -1.0) ? actualDouble : static_cast<double>(longValue);

	display_all(displayChar, displayInt, displayFloat, displayDouble);
}
