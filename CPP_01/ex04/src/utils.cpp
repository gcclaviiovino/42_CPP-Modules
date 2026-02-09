#include "Sed.hpp"

void	err_param(std::string error)
{
	std::cout << "Error." << std::endl;
	if (error == "num")
		std::cout << "Input must consist of three parameters." << std::endl;
	else if (error == "empty")
		std::cout << "Parameters must be non-empty strings." << std::endl;
	else if (error == "file")
	{
		std::cout << "File could not be opened." << std::endl;
		std::cout << "Please check if the file exists and if you have the right permissions." << std::endl;
	}
}

std::string	make_substitution(std::ifstream& filestream, std::string& s1, std::string& s2)
{
	std::string	output = "";
	int			len = s1.length();
	std::string	buff;
	size_t		found;
	bool		first = true;

	while (std::getline(filestream, buff))
	{
		size_t		pos = 0;

		if (!first)
			output += "\n";
		while ((found = buff.find(s1, pos)) != std::string::npos)
		{
			output += buff.substr(pos, found - pos);
			output += s2;
			pos = found + len;
		}
		first = false;
		output += buff.substr(pos);
	}
	return (output);
}