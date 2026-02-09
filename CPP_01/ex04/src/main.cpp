#include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
		return (err_param("num"), 1);
	
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	if (filename.empty() || s1.empty() || s2.empty())
		return (err_param("empty"), 1);

	std::string		outFilename = filename + ".replace";
	std::ifstream	filestream (filename.c_str());

	if (!filestream.is_open())
		return (err_param("file"), 1);

	std::string		output = make_substitution(filestream, s1, s2);
	std::ofstream	outstream (outFilename.c_str());

	outstream << output;

	filestream.close();
	outstream.close();
}